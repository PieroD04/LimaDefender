#pragma once
#include "Juego.h"
namespace LimaDefender
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de FormNivel1
	/// </summary>
	public ref class FormNivel2 : public System::Windows::Forms::Form
	{
	private:
		bool victoria = false;
		int puntaje = 0;
		SoundPlayer^ musica = gcnew SoundPlayer;
		Bitmap^ background = gcnew Bitmap("../Contents/Nivel2_background.png");
		Keys tecla;
	private: System::Windows::Forms::Timer^ timer2;
		   Juego* nivel = new Juego();

	public:
		FormNivel2(void)
		{
			InitializeComponent();
			//
			//TODO: agregar codigo de constructor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estan usando.
		/// </summary>
		~FormNivel2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del disenador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necesario para admitir el Disenador. No se puede modificar
		/// el contenido de este metodo con el editor de codigo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormNivel2::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 20000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FormNivel2::timer2_Tick);
			// 
			// FormNivel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1432, 673);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FormNivel2";
			this->Text = L"Videogame";
			this->Load += gcnew System::EventHandler(this, &FormNivel2::FormNivel2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormNivel2::FormNivel2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormNivel2::FormNivel2_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormNivel2_Load(System::Object^ sender, System::EventArgs^ e)
	{
		musica->SoundLocation = "../Contents/Nivel2_music.wav";
		musica->Load();
		musica->PlayLooping();
	}


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		//Rectangles del Background
		Rectangle areaUsar = Rectangle(0, 0, 1920, 1080);
		Rectangle aumento = Rectangle(0, 0, 1080, 550);
		//Dibujo del Background
		buffer->Graphics->DrawImage(background, aumento, areaUsar, GraphicsUnit::Pixel);
		//Imagen del corazon del boss

		Bitmap^ heart = gcnew Bitmap("../Contents/boss_heart.png");
		buffer->Graphics->DrawImage(heart, 900, 0, 100, 100);
		//Juego
		nivel->Nivel2(buffer);
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;

		if (nivel->getestado() == 1)
		{
			musica->Stop();
			victoria = false;
			puntaje = nivel->getpuntaje();
			Close();
		}
		if (nivel->getestado() == 2)
		{
			musica->Stop();
			victoria = true;
			puntaje = nivel->getpuntaje();
			Close();
		}
	}
		   //Key Press para el disparo

	private: System::Void FormNivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		nivel->detectarTeclas(e->KeyCode, false);


	}
	private: System::Void FormNivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		nivel->detectarTeclas(e->KeyCode, true);
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		nivel->activar_bomba();
		nivel->boss_ataque();
	}
	public: bool HaGanado() { return this->victoria; }
	public: int getPuntaje() { return this->nivel->getpuntaje(); }

	};
}