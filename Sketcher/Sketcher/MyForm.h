#pragma once
#include"Object.h"

namespace Sketcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) 
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStripButton^  toolStripPointButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripLineButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripRectangleButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripCircleButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripCurveButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripBlackButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripRedButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripGreenButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripBlueButton;
	
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripPointButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripLineButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripRectangleButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripCircleButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripCurveButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripBlackButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripRedButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripGreenButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripBlueButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->toolStripPointButton,
					this->toolStripLineButton, this->toolStripRectangleButton, this->toolStripCircleButton, this->toolStripCurveButton, this->toolStripSeparator7,
					this->toolStripBlackButton, this->toolStripRedButton, this->toolStripGreenButton, this->toolStripBlueButton
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(559, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			this->toolStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::toolStrip1_ItemClicked);
			// 
			// toolStripPointButton
			// 
			this->toolStripPointButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripPointButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripPointButton.Image")));
			this->toolStripPointButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripPointButton->Name = L"toolStripPointButton";
			this->toolStripPointButton->Size = System::Drawing::Size(23, 22);
			this->toolStripPointButton->Text = L"Point";
			this->toolStripPointButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripPointButton_Click);
			// 
			// toolStripLineButton
			// 
			this->toolStripLineButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripLineButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLineButton.Image")));
			this->toolStripLineButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripLineButton->Name = L"toolStripLineButton";
			this->toolStripLineButton->Size = System::Drawing::Size(23, 22);
			this->toolStripLineButton->Text = L"Line";
			this->toolStripLineButton->ToolTipText = L"Line";
			this->toolStripLineButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripLineButton_Click);
			// 
			// toolStripRectangleButton
			// 
			this->toolStripRectangleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripRectangleButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripRectangleButton.Image")));
			this->toolStripRectangleButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripRectangleButton->Name = L"toolStripRectangleButton";
			this->toolStripRectangleButton->Size = System::Drawing::Size(23, 22);
			this->toolStripRectangleButton->Text = L"Rectangle";
			this->toolStripRectangleButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripRectangleButton_Click);
			// 
			// toolStripCircleButton
			// 
			this->toolStripCircleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripCircleButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripCircleButton.Image")));
			this->toolStripCircleButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripCircleButton->Name = L"toolStripCircleButton";
			this->toolStripCircleButton->Size = System::Drawing::Size(23, 22);
			this->toolStripCircleButton->Text = L"Circle";
			this->toolStripCircleButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripCircleButton_Click);
			// 
			// toolStripCurveButton
			// 
			this->toolStripCurveButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripCurveButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripCurveButton.Image")));
			this->toolStripCurveButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripCurveButton->Name = L"toolStripCurveButton";
			this->toolStripCurveButton->Size = System::Drawing::Size(23, 22);
			this->toolStripCurveButton->Text = L"Curve";
			this->toolStripCurveButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripCurveButton_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripBlackButton
			// 
			this->toolStripBlackButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripBlackButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripBlackButton.Image")));
			this->toolStripBlackButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripBlackButton->Name = L"toolStripBlackButton";
			this->toolStripBlackButton->Size = System::Drawing::Size(23, 22);
			this->toolStripBlackButton->Text = L"Black";
			this->toolStripBlackButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripBlackButton_Click);
			// 
			// toolStripRedButton
			// 
			this->toolStripRedButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripRedButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripRedButton.Image")));
			this->toolStripRedButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripRedButton->Name = L"toolStripRedButton";
			this->toolStripRedButton->Size = System::Drawing::Size(23, 22);
			this->toolStripRedButton->Text = L"Red";
			this->toolStripRedButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripRedButton_Click);
			// 
			// toolStripGreenButton
			// 
			this->toolStripGreenButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripGreenButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripGreenButton.Image")));
			this->toolStripGreenButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripGreenButton->Name = L"toolStripGreenButton";
			this->toolStripGreenButton->Size = System::Drawing::Size(23, 22);
			this->toolStripGreenButton->Text = L"Green";
			this->toolStripGreenButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripGreenButton_Click);
			// 
			// toolStripBlueButton
			// 
			this->toolStripBlueButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripBlueButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripBlueButton.Image")));
			this->toolStripBlueButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripBlueButton->Name = L"toolStripBlueButton";
			this->toolStripBlueButton->Size = System::Drawing::Size(23, 22);
			this->toolStripBlueButton->Text = L"Blue";
			this->toolStripBlueButton->Click += gcnew System::EventHandler(this, &MyForm::toolStripBlueButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(559, 361);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(559, 296);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Click += gcnew System::EventHandler(this, &MyForm::toolStripBlackButton_Click);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	protected:
		bool IsPoint;
		Object *unit;
		int xs, ys, xf, yf;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		xs = 0;
		ys = 0;
		xf = 0;
		yf = 0;
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e){
	}
	private: System::Void toolStripPointButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{

	}
	private: System::Void toolStripLineButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void toolStripRectangleButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void toolStripCircleButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void toolStripCurveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	
			 ///////////////////////////////////////////
	private: System::Void toolStripBlackButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void toolStripRedButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void toolStripGreenButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void toolStripBlueButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			 //////////////////////////////
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
	}
	private: System::Void toolStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
	}
	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		xs = e->X;
		ys = e->Y;
		xf = e->X;
		yf = e->Y;
		Graphics^ g = this->pictureBox1->CreateGraphics();
	}
	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		xf = e->X;
		yf = e->Y;
		Graphics^ o = this->pictureBox1->CreateGraphics();
		if (IsPoint)
		{
			unit = new TPoint(xf, yf);
			unit->Show(o);
		}
	}
};
}
