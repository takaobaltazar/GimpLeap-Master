#include "About.h"
#pragma once

namespace GimpLeapMaster {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GimpLeapMaster
	/// </summary>
	public ref class GimpLeapMaster : public System::Windows::Forms::Form
	{
	public:
		GimpLeapMaster(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		virtual void removeListener(System::Object^  sender, System::EventArgs^  e);
		virtual void Undo_Click2(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		virtual void Redo_Click2(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		virtual void MoveButton_Click2(System::Object^  sender, System::EventArgs^  e);
		virtual void PencilButton_Click2(System::Object^  sender, System::EventArgs^  e);
		virtual void  OffButton_Click_2(System::Object^  sender, System::EventArgs^  e);
		virtual void  OnButton_Click_2(System::Object^  sender, System::EventArgs^  e);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GimpLeapMaster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  Move_activate;
	protected: 
	private: System::Windows::Forms::PictureBox^  Pencil_activate;
	private: System::Windows::Forms::PictureBox^  ExitButton;
	private: System::Windows::Forms::PictureBox^  HideButton;
	private: System::Windows::Forms::PictureBox^  AboutButton;
	private: System::Windows::Forms::PictureBox^  Move_disable;
	private: System::Windows::Forms::PictureBox^  Pencil_disable;
	private: System::Windows::Forms::PictureBox^  MoveButton;
	private: System::Windows::Forms::PictureBox^  PencilButton;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  Redo_disable;
	private: System::Windows::Forms::PictureBox^  Undo_disable;
	private: System::Windows::Forms::PictureBox^  UndoButton;
	private: System::Windows::Forms::PictureBox^  RedoButton;
	private: System::Windows::Forms::PictureBox^  OffButton;

	private: System::Windows::Forms::PictureBox^  OnButton;





	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::PictureBox^  Undo_pressed;
	private: System::Windows::Forms::PictureBox^  Redo_pressed;

	private: System::Windows::Forms::PictureBox^  Move_hover;
	private: System::Windows::Forms::PictureBox^  Pencil_hover;
	private: System::Windows::Forms::PictureBox^  Hide_hover;
	private: System::Windows::Forms::PictureBox^  About_hover;
	private: System::Windows::Forms::PictureBox^  Undo_hover;
	private: System::Windows::Forms::PictureBox^  Redo_hover;













	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GimpLeapMaster::typeid));
			this->Move_activate = (gcnew System::Windows::Forms::PictureBox());
			this->Pencil_activate = (gcnew System::Windows::Forms::PictureBox());
			this->ExitButton = (gcnew System::Windows::Forms::PictureBox());
			this->HideButton = (gcnew System::Windows::Forms::PictureBox());
			this->AboutButton = (gcnew System::Windows::Forms::PictureBox());
			this->Move_disable = (gcnew System::Windows::Forms::PictureBox());
			this->Pencil_disable = (gcnew System::Windows::Forms::PictureBox());
			this->MoveButton = (gcnew System::Windows::Forms::PictureBox());
			this->PencilButton = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Redo_disable = (gcnew System::Windows::Forms::PictureBox());
			this->Undo_disable = (gcnew System::Windows::Forms::PictureBox());
			this->UndoButton = (gcnew System::Windows::Forms::PictureBox());
			this->RedoButton = (gcnew System::Windows::Forms::PictureBox());
			this->OffButton = (gcnew System::Windows::Forms::PictureBox());
			this->OnButton = (gcnew System::Windows::Forms::PictureBox());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->Undo_pressed = (gcnew System::Windows::Forms::PictureBox());
			this->Redo_pressed = (gcnew System::Windows::Forms::PictureBox());
			this->Move_hover = (gcnew System::Windows::Forms::PictureBox());
			this->Pencil_hover = (gcnew System::Windows::Forms::PictureBox());
			this->Hide_hover = (gcnew System::Windows::Forms::PictureBox());
			this->About_hover = (gcnew System::Windows::Forms::PictureBox());
			this->Undo_hover = (gcnew System::Windows::Forms::PictureBox());
			this->Redo_hover = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Move_activate))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Pencil_activate))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ExitButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HideButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AboutButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Move_disable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Pencil_disable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MoveButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PencilButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Redo_disable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Undo_disable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->UndoButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedoButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OffButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OnButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Undo_pressed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Redo_pressed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Move_hover))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Pencil_hover))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Hide_hover))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->About_hover))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Undo_hover))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Redo_hover))->BeginInit();
			this->SuspendLayout();
			// 
			// Move_activate
			// 
			this->Move_activate->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Move_activate, L"Move_activate");
			this->Move_activate->Name = L"Move_activate";
			this->Move_activate->TabStop = false;
			this->Move_activate->Click += gcnew System::EventHandler(this, &GimpLeapMaster::Move_activate_Click_1);
			// 
			// Pencil_activate
			// 
			this->Pencil_activate->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Pencil_activate, L"Pencil_activate");
			this->Pencil_activate->Name = L"Pencil_activate";
			this->Pencil_activate->TabStop = false;
			this->Pencil_activate->Click += gcnew System::EventHandler(this, &GimpLeapMaster::Pencil_activate_Click_1);
			// 
			// ExitButton
			// 
			this->ExitButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->ExitButton, L"ExitButton");
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->TabStop = false;
			this->ExitButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::removeListener);
			this->ExitButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::ExitButton_Click_1);
			// 
			// HideButton
			// 
			this->HideButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->HideButton, L"HideButton");
			this->HideButton->Name = L"HideButton";
			this->HideButton->TabStop = false;
			this->HideButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::HideButton_Click_1);
			this->HideButton->MouseHover += gcnew System::EventHandler(this, &GimpLeapMaster::HideButton_MouseHover);
			// 
			// AboutButton
			// 
			this->AboutButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->AboutButton, L"AboutButton");
			this->AboutButton->Name = L"AboutButton";
			this->AboutButton->TabStop = false;
			this->AboutButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::AboutButton_Click_1);
			this->AboutButton->MouseHover += gcnew System::EventHandler(this, &GimpLeapMaster::AboutButton_MouseHover);
			// 
			// Move_disable
			// 
			resources->ApplyResources(this->Move_disable, L"Move_disable");
			this->Move_disable->Name = L"Move_disable";
			this->Move_disable->TabStop = false;
			// 
			// Pencil_disable
			// 
			resources->ApplyResources(this->Pencil_disable, L"Pencil_disable");
			this->Pencil_disable->Name = L"Pencil_disable";
			this->Pencil_disable->TabStop = false;
			// 
			// MoveButton
			// 
			this->MoveButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->MoveButton, L"MoveButton");
			this->MoveButton->Name = L"MoveButton";
			this->MoveButton->TabStop = false;
			this->MoveButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::MoveButton_Click_1);
			this->MoveButton->MouseLeave += gcnew System::EventHandler(this, &GimpLeapMaster::MoveButton_MouseLeave);
			this->MoveButton->MouseHover += gcnew System::EventHandler(this, &GimpLeapMaster::MoveButton_MouseHover);
			// 
			// PencilButton
			// 
			this->PencilButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->PencilButton, L"PencilButton");
			this->PencilButton->Name = L"PencilButton";
			this->PencilButton->TabStop = false;
			this->PencilButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::PencilButton_Click_1);
			this->PencilButton->MouseHover += gcnew System::EventHandler(this, &GimpLeapMaster::PencilButton_MouseHover);
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// Redo_disable
			// 
			resources->ApplyResources(this->Redo_disable, L"Redo_disable");
			this->Redo_disable->Name = L"Redo_disable";
			this->Redo_disable->TabStop = false;
			// 
			// Undo_disable
			// 
			resources->ApplyResources(this->Undo_disable, L"Undo_disable");
			this->Undo_disable->Name = L"Undo_disable";
			this->Undo_disable->TabStop = false;
			// 
			// UndoButton
			// 
			this->UndoButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->UndoButton, L"UndoButton");
			this->UndoButton->Name = L"UndoButton";
			this->UndoButton->TabStop = false;
			this->UndoButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::UndoButton_MouseDown);
			this->UndoButton->MouseHover += gcnew System::EventHandler(this, &GimpLeapMaster::UndoButton_MouseHover);
			this->UndoButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::UndoButton_MouseUp);
			// 
			// RedoButton
			// 
			this->RedoButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->RedoButton, L"RedoButton");
			this->RedoButton->Name = L"RedoButton";
			this->RedoButton->TabStop = false;
			this->RedoButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::RedoButton_MouseDown);
			this->RedoButton->MouseHover += gcnew System::EventHandler(this, &GimpLeapMaster::RedoButton_MouseHover);
			this->RedoButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::RedoButton_MouseUp);
			// 
			// OffButton
			// 
			this->OffButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->OffButton, L"OffButton");
			this->OffButton->Name = L"OffButton";
			this->OffButton->TabStop = false;
			this->OffButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::OffButton_Click_2);
			this->OffButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::OffButton_MouseUp);
			// 
			// OnButton
			// mmm
			this->OnButton->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->OnButton, L"OnButton");
			this->OnButton->Name = L"OnButton";
			this->OnButton->TabStop = false; 
			this->OnButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::OnButton_Click_2);
			this->OnButton->Click += gcnew System::EventHandler(this, &GimpLeapMaster::OnButton_Click_1);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->BalloonTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			resources->ApplyResources(this->notifyIcon1, L"notifyIcon1");
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::notifyIcon1_MouseDoubleClick_1);
			// 
			// Undo_pressed
			// 
			this->Undo_pressed->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Undo_pressed, L"Undo_pressed");
			this->Undo_pressed->Name = L"Undo_pressed";
			this->Undo_pressed->TabStop = false;
			this->Undo_pressed->Click += gcnew System::EventHandler(this, &GimpLeapMaster::Undo_pressed_Click);
			// 
			// Redo_pressed
			// 
			this->Redo_pressed->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Redo_pressed, L"Redo_pressed");
			this->Redo_pressed->Name = L"Redo_pressed";
			this->Redo_pressed->TabStop = false;

			// 
			// Move_hover
			// 
			this->Move_hover->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Move_hover, L"Move_hover");
			this->Move_hover->Name = L"Move_hover";
			this->Move_hover->TabStop = false;
			this->Move_hover->Click += gcnew System::EventHandler(this, &GimpLeapMaster::MoveButton_Click2);
			this->Move_hover->Click += gcnew System::EventHandler(this, &GimpLeapMaster::Move_hover_Click);
			this->Move_hover->MouseLeave += gcnew System::EventHandler(this, &GimpLeapMaster::Move_hover_MouseLeave);
			// 
			// Pencil_hover
			// 
			this->Pencil_hover->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Pencil_hover, L"Pencil_hover");
			this->Pencil_hover->Name = L"Pencil_hover";
			this->Pencil_hover->TabStop = false;
			this->Pencil_hover->Click += gcnew System::EventHandler(this, &GimpLeapMaster::PencilButton_Click2);
			this->Pencil_hover->Click += gcnew System::EventHandler(this, &GimpLeapMaster::Pencil_hover_Click);
			this->Pencil_hover->MouseLeave += gcnew System::EventHandler(this, &GimpLeapMaster::Pencil_hover_MouseLeave);
			// 
			// Hide_hover
			// 
			this->Hide_hover->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Hide_hover, L"Hide_hover");
			this->Hide_hover->Name = L"Hide_hover";
			this->Hide_hover->TabStop = false;
			this->Hide_hover->Click += gcnew System::EventHandler(this, &GimpLeapMaster::Hide_hover_Click);
			this->Hide_hover->MouseLeave += gcnew System::EventHandler(this, &GimpLeapMaster::Hide_hover_MouseLeave);
			// 
			// About_hover
			// 
			this->About_hover->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->About_hover, L"About_hover");
			this->About_hover->Name = L"About_hover";
			this->About_hover->TabStop = false;
			this->About_hover->Click += gcnew System::EventHandler(this, &GimpLeapMaster::About_hover_Click);
			this->About_hover->MouseLeave += gcnew System::EventHandler(this, &GimpLeapMaster::About_hover_MouseLeave);
			// 
			// Undo_hover
			// 
			this->Undo_hover->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Undo_hover, L"Undo_hover");
			this->Undo_hover->Name = L"Undo_hover";
			this->Undo_hover->TabStop = false;
			this->Undo_hover->Click += gcnew System::EventHandler(this, &GimpLeapMaster::Undo_hover_Click);
			this->Undo_hover->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::Undo_hover_MouseDown);
			this->Undo_hover->MouseLeave += gcnew System::EventHandler(this, &GimpLeapMaster::Undo_hover_MouseLeave);
			this->Undo_hover->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::Undo_Click2);
			this->Undo_hover->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::Undo_hover_MouseUp);
			// 
			// Redo_hover
			// 
			this->Redo_hover->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->Redo_hover, L"Redo_hover");
			this->Redo_hover->Name = L"Redo_hover";
			this->Redo_hover->TabStop = false;
			this->Redo_hover->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::Redo_hover_MouseDown);
			this->Redo_hover->MouseLeave += gcnew System::EventHandler(this, &GimpLeapMaster::Redo_hover_MouseLeave);
			this->Redo_hover->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::Redo_Click2);
			this->Redo_hover->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GimpLeapMaster::Redo_hover_MouseUp);
			// 
			// GimpLeapMaster
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ControlBox = false;
			this->Controls->Add(this->Redo_hover);
			this->Controls->Add(this->Undo_hover);
			this->Controls->Add(this->About_hover);
			this->Controls->Add(this->Hide_hover);
			this->Controls->Add(this->Pencil_hover);
			this->Controls->Add(this->Move_hover);
			this->Controls->Add(this->Redo_pressed);
			this->Controls->Add(this->Undo_pressed);
			this->Controls->Add(this->Move_activate);
			this->Controls->Add(this->Pencil_activate);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->HideButton);
			this->Controls->Add(this->AboutButton);
			this->Controls->Add(this->Move_disable);
			this->Controls->Add(this->Pencil_disable);
			this->Controls->Add(this->MoveButton);
			this->Controls->Add(this->PencilButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Redo_disable);
			this->Controls->Add(this->Undo_disable);
			this->Controls->Add(this->UndoButton);
			this->Controls->Add(this->RedoButton);
			this->Controls->Add(this->OffButton);
			this->Controls->Add(this->OnButton);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"GimpLeapMaster";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &GimpLeapMaster::GimpLeapMaster_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Move_activate))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Pencil_activate))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ExitButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HideButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AboutButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Move_disable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Pencil_disable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MoveButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PencilButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Redo_disable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Undo_disable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->UndoButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedoButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OffButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OnButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Undo_pressed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Redo_pressed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Move_hover))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Pencil_hover))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Hide_hover))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->About_hover))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Undo_hover))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Redo_hover))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Undo_hover_Click(System::Object^  sender, System::EventArgs^  e) {
this->Close();		 }
private: System::Void Undo_pressed_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void MoveButton_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		}

private: System::Void Move_hover_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	
		 }
private: System::Void HideButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		Hide_hover->Visible=true;
		HideButton->Visible=false;
		 }
private: System::Void MoveButton_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void RedoButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void GimpLeapMaster_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Move_activate_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Pencil_activate_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void HideButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void AboutButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Move_disable_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Pencil_disable_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void MoveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void PencilButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Undo_disable_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void OffButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void OnButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 }
		 //Clicked Off Button
private: System::Void OffButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
		OffButton->Visible=false;
		OnButton->Visible=true;
		OnButton->Enabled=true;
		OffButton->Enabled=false;	
		label2->Visible=true;
		label1->Visible=false;
		RedoButton->Visible=true;
		UndoButton->Visible=true;
		Undo_disable->Visible=false;
		Redo_disable->Visible=false;
		PencilButton->Visible=true;
		Move_activate->Visible=true;
		Pencil_disable->Visible=false;
		Move_disable->Visible=false;


		 }
		 //Clicked On Button
private: System::Void OnButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
		OnButton->Visible=false;
		OffButton->Visible=true;
		OnButton->Enabled=false;
		OffButton->Enabled=true;
		label1->Visible=true;
		label2->Visible=false;
		RedoButton->Visible=false;
		UndoButton->Visible=false;
		Undo_disable->Visible=true;
		Redo_disable->Visible=true;
		PencilButton->Visible=false;
		Move_activate->Visible=false;
		Pencil_disable->Visible=true;
		Move_disable->Visible=true;
		//Activated the Pencil
		if((Pencil_activate->Visible==true) || (Move_activate->Visible==true))
		{
			Pencil_activate->Visible=false;
			Move_activate->Visible=false;
		}
		
		 }

private: System::Void Pencil_activate_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
		 }
private: System::Void Move_activate_Click_1(System::Object^  sender, System::EventArgs^  e) {
	
		 }
		 //Clicked Move button
private: System::Void MoveButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
		 }
		 //Clicked Pencil Button
private: System::Void PencilButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
		}
		 //Clicked Hide Button
private: System::Void HideButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
		 }
		 //Clicked About Button

private: System::Void AboutButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
			
		 }
		 //Clicked Exit Button
private: System::Void ExitButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
		 }
		 
private: System::Void notifyIcon1_MouseDoubleClick_1(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }
		 //Pressed down Undo Button
private: System::Void UndoButton_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		 }
		 //Released Undo Button
private: System::Void UndoButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		 }
		 //Pressed down Redo Button
private: System::Void RedoButton_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		 }
		 //Released Redo Button
private: System::Void RedoButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		 }
private: System::Void notifyIcon3_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {	 }
		//Mouse hover in move button

private: System::Void MoveButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		Move_hover->Visible=true;
		MoveButton->Visible=false;
		
		 }
		 //Left the move button
private: System::Void Move_hover_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		Move_hover->Visible=false;
		MoveButton->Visible=true;
		 }
		 //clicked in pencil button
private: System::Void Pencil_hover_Click(System::Object^  sender, System::EventArgs^  e) {
		Pencil_hover->Visible=false;
		Pencil_activate->Visible=true;
		Pencil_disable->Visible=false;
		PencilButton->Visible=false;
		

		if(Move_activate->Visible==true)
		{
			Move_activate->Visible=false;
			MoveButton->Visible=true;
		}
		
		 }
		 //Mouse hover in pencil button
private: System::Void PencilButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		PencilButton->Visible=false;
		Pencil_hover->Visible=true;
		}
		 //Left the pencil button
private: System::Void Pencil_hover_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		Pencil_hover->Visible=false;
		PencilButton->Visible=true;
		 }
		 //Clicked the move hover button
private: System::Void Move_hover_Click(System::Object^  sender, System::EventArgs^  e) {
		Move_hover->Visible=false;
		Move_activate->Visible=true;
		Move_disable->Visible=false;
		MoveButton->Visible=false;
		if(Pencil_activate->Visible==true)
		{
			Pencil_activate->Visible=false;
			PencilButton->Visible=true;
		}
		 }
		 //Left the Hide hover button
private: System::Void Hide_hover_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		Hide_hover->Visible=false;
		HideButton->Visible=true;
		 }
		//Mouse hover in the About button
private: System::Void AboutButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		AboutButton->Visible=false;
		About_hover->Visible=true;
		 }
		//Left the about hover button
private: System::Void About_hover_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		AboutButton->Visible=true;
		About_hover->Visible=false;
		 }
private: System::Void About_hover_Click(System::Object^  sender, System::EventArgs^  e) {
		About ^ about_i = gcnew About();
		about_i->ShowDialog();
		
		AboutButton->Visible=true;
		About_hover->Visible=false;
		//About_activate->Visible=true;
		
		 }
		 //Clicked hide hover button
private: System::Void Hide_hover_Click(System::Object^  sender, System::EventArgs^  e) {
		this->WindowState=FormWindowState(MinimizeBox);
		 }
		 //Mouse hover in the undo button
private: System::Void UndoButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		UndoButton->Visible=false;
		Undo_hover->Visible=true;
		
		 }
		 //Cliked the undo button
private: System::Void UndoButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
		 //Left the undo hover button
private: System::Void Undo_hover_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		UndoButton->Visible=true;
		Undo_hover->Visible=false;
		 }
		 //Left the redo hover button
private: System::Void Redo_hover_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		Redo_hover->Visible=false;
		RedoButton->Visible=true;
		 }
		 //Mouse hover the redo button
private: System::Void RedoButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		Redo_hover->Visible=true;
		RedoButton->Visible=false;
		 }

private: System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
		
		 }
private: System::Void OffButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		
		 }
		 //Pressed down the redo hover button
private: System::Void Redo_hover_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		Redo_hover->Visible=false;
		Redo_pressed->Visible=true;
		 }
		 //Released the redo hover button
private: System::Void Redo_hover_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Redo_hover->Visible=true;
		Redo_pressed->Visible=false;
		 }
		 //Pressed down the undo hover button
private: System::Void Undo_hover_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Undo_hover->Visible=false;
		Undo_pressed->Visible=true;
		 }

		 //Released the undo hover button
private: System::Void Undo_hover_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Undo_hover->Visible=true;
		Undo_pressed->Visible=false;
		}
};
}

