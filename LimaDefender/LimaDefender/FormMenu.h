#pragma once
#include "FormInstrucciones.h"
#include "FormCreditos.h"
#include "FormSelector.h"
namespace LimaDefender {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de FormMenu
	/// </summary>
	public ref class FormMenu : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ fondo = gcnew Bitmap("../Contents/menu_background.jpg");
	private: System::Windows::Forms::Timer^ timer1;
		   Bitmap^ text = gcnew Bitmap("../Contents/texto.png");
	public:
		FormMenu(void)
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
		~FormMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ Jugar;

	private: System::Windows::Forms::Button^ Instrucciones;
	private: System::Windows::Forms::Button^ Creditos;

	private: System::ComponentModel::IContainer^ components;



	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Jugar = (gcnew System::Windows::Forms::Button());
			this->Instrucciones = (gcnew System::Windows::Forms::Button());
			this->Creditos = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Jugar
			// 
			this->Jugar->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Jugar->Font = (gcnew System::Drawing::Font(L"Rockwell", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Jugar->Location = System::Drawing::Point(43, 550);
			this->Jugar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Jugar->Name = L"Jugar";
			this->Jugar->Size = System::Drawing::Size(301, 106);
			this->Jugar->TabIndex = 2;
			this->Jugar->Text = L"Jugar";
			this->Jugar->UseVisualStyleBackColor = false;
			this->Jugar->Click += gcnew System::EventHandler(this, &FormMenu::Jugar_Click);
			// 
			// Instrucciones
			// 
			this->Instrucciones->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Instrucciones->Font = (gcnew System::Drawing::Font(L"Rockwell", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Instrucciones->Location = System::Drawing::Point(403, 550);
			this->Instrucciones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Instrucciones->Name = L"Instrucciones";
			this->Instrucciones->Size = System::Drawing::Size(461, 106);
			this->Instrucciones->TabIndex = 3;
			this->Instrucciones->Text = L"Instrucciones";
			this->Instrucciones->UseVisualStyleBackColor = false;
			this->Instrucciones->Click += gcnew System::EventHandler(this, &FormMenu::Instrucciones_Click);
			// 
			// Creditos
			// 
			this->Creditos->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Creditos->Font = (gcnew System::Drawing::Font(L"Rockwell", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Creditos->Location = System::Drawing::Point(927, 550);
			this->Creditos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Creditos->Name = L"Creditos";
			this->Creditos->Size = System::Drawing::Size(301, 106);
			this->Creditos->TabIndex = 4;
			this->Creditos->Text = L"Creditos";
			this->Creditos->UseVisualStyleBackColor = false;
			this->Creditos->Click += gcnew System::EventHandler(this, &FormMenu::Creditos_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormMenu::timer1_Tick);
			// 
			// FormMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1261, 673);
			this->Controls->Add(this->Creditos);
			this->Controls->Add(this->Instrucciones);
			this->Controls->Add(this->Jugar);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FormMenu";
			this->Text = L"Videogame";
			this->Load += gcnew System::EventHandler(this, &FormMenu::FormMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormMenu_Load(System::Object^ sender, System::EventArgs^ e)
	{
		/*
		SoundPlayer^ musica = gcnew SoundPlayer;
		musica->SoundLocation = "../Contents/menu-music.wav";
		musica->Load();
		musica->PlayLooping();
		*/
		

	}
	private: System::Void Instrucciones_Click(System::Object^ sender, System::EventArgs^ e)
	{
		FormInstrucciones^ form_instrucciones = gcnew FormInstrucciones();
		this->Visible = false;
		form_instrucciones->ShowDialog();
		this->Visible = true;
	}
	private: System::Void Creditos_Click(System::Object^ sender, System::EventArgs^ e)
	{
		FormCreditos^ form_creditos = gcnew FormCreditos();
		this->Visible = false;
		form_creditos->ShowDialog();
		this->Visible = true;
	}
	private: System::Void Jugar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		FormSelector^ form_selector = gcnew FormSelector();
		this->Visible = false;
		form_selector->ShowDialog();
		this->Visible = true;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		//Rectangles del Background
		Rectangle areaUsar = Rectangle(0, 0, 1920, 1080);
		Rectangle aumento = Rectangle(0, 0, 1280, 720);
		//Rectangles del texto
		Rectangle areaUsar_text = Rectangle(0, 0, 4116, 4057);
		Rectangle aumento_text = Rectangle(180, -80, 600, 600);
		//Dibujo del Background
		buffer->Graphics->DrawImage(fondo, aumento, areaUsar, GraphicsUnit::Pixel);
		buffer->Graphics->DrawImage(text, aumento_text, areaUsar_text, GraphicsUnit::Pixel);

		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
};
}
