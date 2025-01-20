#pragma once

namespace LimaDefender {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormCreditos
	/// </summary>
	public ref class FormCreditos : public System::Windows::Forms::Form
	{
	private: Bitmap^ logo = gcnew Bitmap("../Contents/upc_logo.png");
	public:
		FormCreditos(void)
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
		~FormCreditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Titulo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Cerrar;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormCreditos::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Titulo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Cerrar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Titulo
			// 
			this->Titulo->AutoSize = true;
			this->Titulo->Font = (gcnew System::Drawing::Font(L"Rockwell", 40));
			this->Titulo->Location = System::Drawing::Point(12, 9);
			this->Titulo->Name = L"Titulo";
			this->Titulo->Size = System::Drawing::Size(300, 75);
			this->Titulo->BackColor = Color::White;
			this->Titulo->TabIndex = 1;
			this->Titulo->Text = L"Creditos";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormCreditos::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->label1->Location = System::Drawing::Point(20, 103);
			this->label1->Name = L"label1";
			this->label1->BackColor = Color::White;
			this->label1->Size = System::Drawing::Size(196, 39);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Integrantes:";
			// 
			// Cerrar
			// 
			this->Cerrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cerrar->Location = System::Drawing::Point(442, 485);
			this->Cerrar->Name = L"Cerrar";
			this->Cerrar->Size = System::Drawing::Size(108, 36);
			this->Cerrar->TabIndex = 4;
			this->Cerrar->Text = L"Cerrar";
			this->Cerrar->UseVisualStyleBackColor = true;
			this->Cerrar->Click += gcnew System::EventHandler(this, &FormCreditos::Cerrar_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label2->Location = System::Drawing::Point(20, 154);
			this->label2->Name = L"label2";
			this->label2->BackColor = Color::White;
			this->label2->Size = System::Drawing::Size(173, 29);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Piero Delgado";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label3->Location = System::Drawing::Point(20, 200);
			this->label3->Name = L"label3";
			this->label3->BackColor = Color::White;
			this->label3->Size = System::Drawing::Size(228, 29);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Luis Chinchihualpa";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label4->Location = System::Drawing::Point(20, 245);
			this->label4->Name = L"label4";
			this->label4->BackColor = Color::White;
			this->label4->Size = System::Drawing::Size(115, 29);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Bryan Fu";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label5->Location = System::Drawing::Point(20, 289);
			this->label5->Name = L"label5";
			this->label5->BackColor = Color::White;
			this->label5->Size = System::Drawing::Size(185, 29);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Gustavo Huilca";
			// 
			// FormCreditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 533);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Cerrar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Titulo);
			this->Name = L"FormCreditos";
			this->Text = L"Videogame";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cerrar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			Graphics^ g = this->CreateGraphics();
			BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
			buffer->Graphics->Clear(Color::White);
			//Rectangles logo
			Rectangle aumento = Rectangle(300, 0, 100, 100);
			Rectangle areaUsar = Rectangle(0, 0, 300, 299);

			//Dibujo del Background
			buffer->Graphics->DrawImage(logo, aumento, areaUsar, GraphicsUnit::Pixel);

			buffer->Render(g);
			delete buffer;
			delete espacio;
			delete g;
		}
	};
}
