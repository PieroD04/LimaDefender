#pragma once
#include "FormNivel1.h"
#include "FormNivel2.h"
#include "FormDerrota.h"
#include "FormVictoria.h"
namespace LimaDefender {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormSelector
	/// </summary>
	public ref class FormSelector : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ img_nivel1 = gcnew Bitmap("../Contents/Nivel1_background.png");
		Bitmap^ img_nivel2 = gcnew Bitmap("../Contents/Nivel2_background.png");
	public:
		FormSelector(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormSelector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Titulo;
	private: System::Windows::Forms::Button^ Cerrar;
	private: System::Windows::Forms::Button^ Nivel2;
	private: System::Windows::Forms::Button^ Nivel1;
	private: System::Windows::Forms::Timer^ timer1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormSelector::typeid));
			this->Titulo = (gcnew System::Windows::Forms::Label());
			this->Cerrar = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Nivel2 = (gcnew System::Windows::Forms::Button());
			this->Nivel1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Titulo
			// 
			this->Titulo->AutoSize = true;
			this->Titulo->Font = (gcnew System::Drawing::Font(L"Rockwell", 40));
			this->Titulo->Location = System::Drawing::Point(12, 9);
			this->Titulo->Name = L"Titulo";
			this->Titulo->Size = System::Drawing::Size(263, 75);
			this->Titulo->BackColor = Color::White;
			this->Titulo->TabIndex = 2;
			this->Titulo->Text = L"Niveles";
			// 
			// Cerrar
			// 
			this->Cerrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cerrar->Location = System::Drawing::Point(442, 485);
			this->Cerrar->Name = L"Cerrar";
			this->Cerrar->Size = System::Drawing::Size(108, 36);
			this->Cerrar->TabIndex = 5;
			this->Cerrar->Text = L"Cerrar";
			this->Cerrar->UseVisualStyleBackColor = true;
			this->Cerrar->Click += gcnew System::EventHandler(this, &FormSelector::Cerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormSelector::timer1_Tick);
			// 
			// Nivel2
			// 
			this->Nivel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nivel2->Location = System::Drawing::Point(356, 362);
			this->Nivel2->Name = L"Nivel2";
			this->Nivel2->Size = System::Drawing::Size(131, 50);
			this->Nivel2->TabIndex = 6;
			this->Nivel2->Text = L"Nivel 2";
			this->Nivel2->UseVisualStyleBackColor = true;
			this->Nivel2->Click += gcnew System::EventHandler(this, &FormSelector::Nivel2_Click);
			// 
			// Nivel1
			// 
			this->Nivel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nivel1->Location = System::Drawing::Point(356, 175);
			this->Nivel1->Name = L"Nivel1";
			this->Nivel1->Size = System::Drawing::Size(131, 50);
			this->Nivel1->TabIndex = 7;
			this->Nivel1->Text = L"Nivel 1";
			this->Nivel1->UseVisualStyleBackColor = true;
			this->Nivel1->Click += gcnew System::EventHandler(this, &FormSelector::Nivel1_Click);
			// 
			// FormSelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 533);
			this->Controls->Add(this->Nivel1);
			this->Controls->Add(this->Nivel2);
			this->Controls->Add(this->Cerrar);
			this->Controls->Add(this->Titulo);
			this->Name = L"FormSelector";
			this->Text = L"Videogame";
			this->Load += gcnew System::EventHandler(this, &FormSelector::FormSelector_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cerrar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void Nivel1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		FormNivel1^ nivel1 = gcnew FormNivel1();
		this->Visible = false;
		nivel1->ShowDialog();

		if (nivel1->HaGanado() == true) 
		{
			FormVictoria^ victoria = gcnew FormVictoria();
			victoria->colocarPuntaje(nivel1->getPuntaje());
			victoria->ShowDialog();
		} 
		else
		{
			FormDerrota^ derrota = gcnew FormDerrota();
			derrota->colocarPuntaje(nivel1->getPuntaje());
			derrota->ShowDialog();
		}

		this->Visible = true;
	}
	private: System::Void Nivel2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		FormNivel2^ nivel2 = gcnew FormNivel2();
		this->Visible = false;
		nivel2->ShowDialog();

		if (nivel2->HaGanado() == true)
		{
			FormVictoria^ victoria = gcnew FormVictoria();
			victoria->colocarPuntaje(nivel2->getPuntaje());
			victoria->ShowDialog();
		}
		else
		{
			FormDerrota^ derrota = gcnew FormDerrota();
			derrota->colocarPuntaje(nivel2->getPuntaje());
			derrota->ShowDialog();
		}

		this->Visible = true;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
			   Graphics^ g = this->CreateGraphics();
			   BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
			   BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
			   buffer->Graphics->Clear(Color::White);
			   //Rectangles nivel 1
			   Rectangle aumento = Rectangle(40, 110, 200, 100);
			   Rectangle areaUsar = Rectangle(0, 0, 1920, 1080);
			   //Rectangles nivel 2
			   Rectangle aumento2 = Rectangle(40, 265, 200, 100);
			   Rectangle areaUsar2 = Rectangle(0, 0, 1920, 1080);
			      //Dibujo del Background
			   buffer->Graphics->DrawImage(img_nivel1, aumento, areaUsar, GraphicsUnit::Pixel);
			   buffer->Graphics->DrawImage(img_nivel2, aumento2, areaUsar2, GraphicsUnit::Pixel);
			   			
			   buffer->Render(g);
			   delete buffer;
			   delete espacio;
			   delete g;
	}

	private: System::Void FormSelector_Load(System::Object^ sender, System::EventArgs^ e)
	{

	}
	};
}
