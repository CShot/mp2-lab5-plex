#pragma once
#include "Object.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Curve.h"
#include "Sketch.h"

namespace Sketcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum class ElementType { LINE, RECTANGLE, CIRCLE, CURVE, ELLIPSE };
	enum class Mode{ Normal, Move };

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) : elementType(ElementType::CURVE), color(Color::Black), mode(Mode::Normal) 
			, drawing(false)
			, firstPoint(0)
			, tempElement(nullptr)
			, highlightedElement(nullptr)
			, sketch(gcnew Sketch())
		{
			InitializeComponent();
			//
			SetElementTypeButtonsState();
			SetColorButtonsState();
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  elementToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rectangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  circleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  curveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  greenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blueToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripButton^  toolStripLineButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripRectangleButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripCircleButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripCurveButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStripButton^  toolStripBlackButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripRedButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripGreenButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripBlueButton;
	private: System::Windows::Forms::ToolStripMenuItem^  ellipseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  toolStripEllipseButton;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  moveContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sendToBackContextMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  contextSeparator;


	private: System::Windows::Forms::ToolStripMenuItem^  lineContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rectangleContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  circleContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ellipseContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  curveContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blackContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  greenContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blueContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cleanToolStripMenuItem;















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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->elementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->curveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ellipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripCurveButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripLineButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripRectangleButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripCircleButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripEllipseButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripBlackButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripRedButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripGreenButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripBlueButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->moveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sendToBackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->curveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ellipseContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greenContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cleanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->elementToolStripMenuItem,
					this->colorToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(821, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// elementToolStripMenuItem
			// 
			this->elementToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->curveToolStripMenuItem,
					this->lineToolStripMenuItem, this->rectangleToolStripMenuItem, this->circleToolStripMenuItem, this->ellipseToolStripMenuItem
			});
			this->elementToolStripMenuItem->Name = L"elementToolStripMenuItem";
			this->elementToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->elementToolStripMenuItem->Text = L"E&lement";
			this->elementToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &MyForm::elementToolStripMenuItem_DropDownOpening);
			this->elementToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::elementToolStripMenuItem_Click);
			// 
			// curveToolStripMenuItem
			// 
			this->curveToolStripMenuItem->Name = L"curveToolStripMenuItem";
			this->curveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::P));
			this->curveToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->curveToolStripMenuItem->Text = L"Point";
			this->curveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::curveToolStripMenuItem_Click);
			// 
			// lineToolStripMenuItem
			// 
			this->lineToolStripMenuItem->Name = L"lineToolStripMenuItem";
			this->lineToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::L));
			this->lineToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->lineToolStripMenuItem->Text = L"Line";
			this->lineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lineToolStripMenuItem_Click);
			// 
			// rectangleToolStripMenuItem
			// 
			this->rectangleToolStripMenuItem->Name = L"rectangleToolStripMenuItem";
			this->rectangleToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::R));
			this->rectangleToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->rectangleToolStripMenuItem->Text = L"Rectangle";
			this->rectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rectangleToolStripMenuItem_Click);
			// 
			// circleToolStripMenuItem
			// 
			this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
			this->circleToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::C));
			this->circleToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->circleToolStripMenuItem->Text = L"Circle";
			this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// ellipseToolStripMenuItem
			// 
			this->ellipseToolStripMenuItem->Name = L"ellipseToolStripMenuItem";
			this->ellipseToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::E));
			this->ellipseToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->ellipseToolStripMenuItem->Text = L"Ellipse";
			this->ellipseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ellipseToolStripMenuItem_Click);
			// 
			// colorToolStripMenuItem
			// 
			this->colorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->blackToolStripMenuItem,
					this->redToolStripMenuItem, this->greenToolStripMenuItem, this->blueToolStripMenuItem
			});
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			this->colorToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->colorToolStripMenuItem->Text = L"&Color";
			this->colorToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &MyForm::colorToolStripMenuItem_DropDownOpening);
			// 
			// blackToolStripMenuItem
			// 
			this->blackToolStripMenuItem->Name = L"blackToolStripMenuItem";
			this->blackToolStripMenuItem->Size = System::Drawing::Size(105, 22);
			this->blackToolStripMenuItem->Text = L"Black";
			this->blackToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::blackToolStripMenuItem_Click);
			// 
			// redToolStripMenuItem
			// 
			this->redToolStripMenuItem->Name = L"redToolStripMenuItem";
			this->redToolStripMenuItem->Size = System::Drawing::Size(105, 22);
			this->redToolStripMenuItem->Text = L"Red";
			this->redToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::redToolStripMenuItem_Click);
			// 
			// greenToolStripMenuItem
			// 
			this->greenToolStripMenuItem->Name = L"greenToolStripMenuItem";
			this->greenToolStripMenuItem->Size = System::Drawing::Size(105, 22);
			this->greenToolStripMenuItem->Text = L"Green";
			this->greenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::greenToolStripMenuItem_Click);
			// 
			// blueToolStripMenuItem
			// 
			this->blueToolStripMenuItem->Name = L"blueToolStripMenuItem";
			this->blueToolStripMenuItem->Size = System::Drawing::Size(105, 22);
			this->blueToolStripMenuItem->Text = L"Blue";
			this->blueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::blueToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->toolStripSeparator6,
					this->toolStripCurveButton, this->toolStripLineButton, this->toolStripRectangleButton, this->toolStripCircleButton, this->toolStripEllipseButton,
					this->toolStripSeparator7, this->toolStripBlackButton, this->toolStripRedButton, this->toolStripGreenButton, this->toolStripBlueButton
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(821, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripCurveButton
			// 
			this->toolStripCurveButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripCurveButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripCurveButton.Image")));
			this->toolStripCurveButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripCurveButton->Name = L"toolStripCurveButton";
			this->toolStripCurveButton->Size = System::Drawing::Size(23, 22);
			this->toolStripCurveButton->Text = L"Curves";
			this->toolStripCurveButton->ToolTipText = L"Draw point";
			this->toolStripCurveButton->Click += gcnew System::EventHandler(this, &MyForm::curveToolStripMenuItem_Click);
			// 
			// toolStripLineButton
			// 
			this->toolStripLineButton->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripLineButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripLineButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLineButton.Image")));
			this->toolStripLineButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripLineButton->Name = L"toolStripLineButton";
			this->toolStripLineButton->Size = System::Drawing::Size(23, 22);
			this->toolStripLineButton->Text = L"Lines";
			this->toolStripLineButton->ToolTipText = L"Draw lines";
			this->toolStripLineButton->Click += gcnew System::EventHandler(this, &MyForm::lineToolStripMenuItem_Click);
			// 
			// toolStripRectangleButton
			// 
			this->toolStripRectangleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripRectangleButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripRectangleButton.Image")));
			this->toolStripRectangleButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripRectangleButton->Name = L"toolStripRectangleButton";
			this->toolStripRectangleButton->Size = System::Drawing::Size(23, 22);
			this->toolStripRectangleButton->Text = L"Rectangles";
			this->toolStripRectangleButton->ToolTipText = L"Draw rectangles";
			this->toolStripRectangleButton->Click += gcnew System::EventHandler(this, &MyForm::rectangleToolStripMenuItem_Click);
			// 
			// toolStripCircleButton
			// 
			this->toolStripCircleButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripCircleButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripCircleButton.Image")));
			this->toolStripCircleButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripCircleButton->Name = L"toolStripCircleButton";
			this->toolStripCircleButton->Size = System::Drawing::Size(23, 22);
			this->toolStripCircleButton->Text = L"Circles";
			this->toolStripCircleButton->ToolTipText = L"Draw circles";
			this->toolStripCircleButton->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// toolStripEllipseButton
			// 
			this->toolStripEllipseButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripEllipseButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripEllipseButton.Image")));
			this->toolStripEllipseButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripEllipseButton->Name = L"toolStripEllipseButton";
			this->toolStripEllipseButton->Size = System::Drawing::Size(23, 22);
			this->toolStripEllipseButton->Text = L"Ellipses";
			this->toolStripEllipseButton->Click += gcnew System::EventHandler(this, &MyForm::ellipseToolStripMenuItem_Click);
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
			this->toolStripBlackButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripBlackButton->Name = L"toolStripBlackButton";
			this->toolStripBlackButton->Size = System::Drawing::Size(23, 22);
			this->toolStripBlackButton->Text = L"Black";
			this->toolStripBlackButton->ToolTipText = L"Draw in black";
			this->toolStripBlackButton->Click += gcnew System::EventHandler(this, &MyForm::blackToolStripMenuItem_Click);
			// 
			// toolStripRedButton
			// 
			this->toolStripRedButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripRedButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripRedButton.Image")));
			this->toolStripRedButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripRedButton->Name = L"toolStripRedButton";
			this->toolStripRedButton->Size = System::Drawing::Size(23, 22);
			this->toolStripRedButton->Text = L"Red";
			this->toolStripRedButton->ToolTipText = L"Draw in red";
			this->toolStripRedButton->Click += gcnew System::EventHandler(this, &MyForm::redToolStripMenuItem_Click);
			// 
			// toolStripGreenButton
			// 
			this->toolStripGreenButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripGreenButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripGreenButton.Image")));
			this->toolStripGreenButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripGreenButton->Name = L"toolStripGreenButton";
			this->toolStripGreenButton->Size = System::Drawing::Size(23, 22);
			this->toolStripGreenButton->Text = L"Green";
			this->toolStripGreenButton->ToolTipText = L"Draw in green";
			this->toolStripGreenButton->Click += gcnew System::EventHandler(this, &MyForm::greenToolStripMenuItem_Click);
			// 
			// toolStripBlueButton
			// 
			this->toolStripBlueButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripBlueButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripBlueButton.Image")));
			this->toolStripBlueButton->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripBlueButton->Name = L"toolStripBlueButton";
			this->toolStripBlueButton->Size = System::Drawing::Size(23, 22);
			this->toolStripBlueButton->Text = L"Blue";
			this->toolStripBlueButton->ToolTipText = L"Draw in blue";
			this->toolStripBlueButton->Click += gcnew System::EventHandler(this, &MyForm::blueToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(14) {
				this->moveContextMenuItem,
					this->deleteContextMenuItem, this->sendToBackContextMenuItem, this->contextSeparator, this->curveContextMenuItem, this->lineContextMenuItem,
					this->rectangleContextMenuItem, this->ellipseContextMenuItem, this->circleContextMenuItem, this->blackContextMenuItem, this->redContextMenuItem,
					this->greenContextMenuItem, this->blueContextMenuItem, this->cleanToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(161, 296);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::contextMenuStrip1_Opening_1);
			// 
			// moveContextMenuItem
			// 
			this->moveContextMenuItem->Name = L"moveContextMenuItem";
			this->moveContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->moveContextMenuItem->Text = L"Move";
			this->moveContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::moveContextMenuItem_Click);
			// 
			// deleteContextMenuItem
			// 
			this->deleteContextMenuItem->Name = L"deleteContextMenuItem";
			this->deleteContextMenuItem->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->deleteContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->deleteContextMenuItem->Text = L"Delete";
			this->deleteContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteContextMenuItem_Click);
			// 
			// sendToBackContextMenuItem
			// 
			this->sendToBackContextMenuItem->Name = L"sendToBackContextMenuItem";
			this->sendToBackContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->sendToBackContextMenuItem->Text = L"Back";
			this->sendToBackContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sendToBackContextMenuItem_Click);
			// 
			// contextSeparator
			// 
			this->contextSeparator->Name = L"contextSeparator";
			this->contextSeparator->Size = System::Drawing::Size(157, 6);
			// 
			// curveContextMenuItem
			// 
			this->curveContextMenuItem->Name = L"curveContextMenuItem";
			this->curveContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->curveContextMenuItem->Text = L"Point";
			this->curveContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::curveToolStripMenuItem_Click);
			// 
			// lineContextMenuItem
			// 
			this->lineContextMenuItem->Name = L"lineContextMenuItem";
			this->lineContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->lineContextMenuItem->Text = L"Line";
			this->lineContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lineToolStripMenuItem_Click);
			// 
			// rectangleContextMenuItem
			// 
			this->rectangleContextMenuItem->Name = L"rectangleContextMenuItem";
			this->rectangleContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->rectangleContextMenuItem->Text = L"Rectangle";
			this->rectangleContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rectangleToolStripMenuItem_Click);
			// 
			// ellipseContextMenuItem
			// 
			this->ellipseContextMenuItem->Name = L"ellipseContextMenuItem";
			this->ellipseContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->ellipseContextMenuItem->Text = L"Ellipse";
			this->ellipseContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ellipseToolStripMenuItem_Click);
			// 
			// circleContextMenuItem
			// 
			this->circleContextMenuItem->Name = L"circleContextMenuItem";
			this->circleContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->circleContextMenuItem->Text = L"Circle";
			this->circleContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// blackContextMenuItem
			// 
			this->blackContextMenuItem->Name = L"blackContextMenuItem";
			this->blackContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->blackContextMenuItem->Text = L"Black";
			this->blackContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::blackToolStripMenuItem_Click);
			// 
			// redContextMenuItem
			// 
			this->redContextMenuItem->Name = L"redContextMenuItem";
			this->redContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->redContextMenuItem->Text = L"Red";
			this->redContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::redToolStripMenuItem_Click);
			// 
			// greenContextMenuItem
			// 
			this->greenContextMenuItem->Name = L"greenContextMenuItem";
			this->greenContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->greenContextMenuItem->Text = L"Green";
			this->greenContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::greenToolStripMenuItem_Click);
			// 
			// blueContextMenuItem
			// 
			this->blueContextMenuItem->Name = L"blueContextMenuItem";
			this->blueContextMenuItem->Size = System::Drawing::Size(160, 22);
			this->blueContextMenuItem->Text = L"Blue";
			this->blueContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::blueToolStripMenuItem_Click);
			// 
			// cleanToolStripMenuItem
			// 
			this->cleanToolStripMenuItem->Name = L"cleanToolStripMenuItem";
			this->cleanToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Shift | System::Windows::Forms::Keys::Delete));
			this->cleanToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->cleanToolStripMenuItem->Text = L"Clean";
			this->cleanToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cleanContextMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(821, 499);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Sketcher";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Sketch^ sketch;
	bool drawing;
	Point firstPoint;
	Element^ tempElement;
	ElementType elementType;
	Color color;
	Element^ highlightedElement;
	private: 
	Mode mode;

	private: System::Void moveContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		mode = Mode::Move;
	}
	private: System::Void lineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		elementType = ElementType::LINE;
		SetElementTypeButtonsState();
	}
	private: System::Void rectangleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		elementType = ElementType::RECTANGLE;
		SetElementTypeButtonsState();
	}
	private: System::Void circleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		elementType = ElementType::CIRCLE;
		SetElementTypeButtonsState();
	}
	private: System::Void curveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		elementType = ElementType::CURVE;
		SetElementTypeButtonsState();
	}
	private: System::Void blackToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		color = Color::Black;
		SetColorButtonsState();
	}
	private: System::Void redToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		color = Color::Red;
		SetColorButtonsState();
	}
	private: System::Void greenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		color = Color::Green;
		SetColorButtonsState();
	}
	private: System::Void blueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		color = Color::Blue;
		SetColorButtonsState();
	}
			 
	private: System::Void elementToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
		lineToolStripMenuItem->Checked = elementType == ElementType::LINE;
		rectangleToolStripMenuItem->Checked = elementType == ElementType::RECTANGLE;
		circleToolStripMenuItem->Checked = elementType == ElementType::CIRCLE;
		curveToolStripMenuItem->Checked = elementType == ElementType::CURVE;
		ellipseToolStripMenuItem->Checked = elementType == ElementType::ELLIPSE;
	}
	private: System::Void colorToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
		blackToolStripMenuItem->Checked = color == Color::Black;
		redToolStripMenuItem->Checked = color == Color::Red;
		greenToolStripMenuItem->Checked = color == Color::Green;
		blueToolStripMenuItem->Checked = color == Color::Blue;
	}

			 
			 void SetElementTypeButtonsState(void)
			 {
				 toolStripLineButton->Checked = elementType == ElementType::LINE;
				 toolStripRectangleButton->Checked = elementType == ElementType::RECTANGLE;
				 toolStripCircleButton->Checked = elementType == ElementType::CIRCLE;
				 toolStripCurveButton->Checked = elementType == ElementType::CURVE;
				 toolStripEllipseButton->Checked = elementType == ElementType::ELLIPSE;
			 }

			 
			 void SetColorButtonsState(void)
			 {
				 toolStripBlackButton->Checked = color == Color::Black;
				 toolStripRedButton->Checked = color == Color::Red;
				 toolStripGreenButton->Checked = color == Color::Green;
				 toolStripBlueButton->Checked = color == Color::Blue;
			 }

	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if(e->Button==System::Windows::Forms::MouseButtons::Left)
    {
        if(mode==Mode::Normal)
            drawing=true;

        firstPoint=e->Location;
    }
	}

	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (drawing)
		{
			if (tempElement)
				Invalidate(tempElement->bound);
			switch (elementType)
			{
			case ElementType::LINE:
				tempElement = gcnew Line(color, firstPoint, e->Location);
				break;
			case ElementType::RECTANGLE:
				tempElement = gcnew Rectangle(color, firstPoint, e->Location);
				break;
			case ElementType::CIRCLE:
				tempElement = gcnew Circle(color, firstPoint, e->Location);
				break;
			/*case ElementType::CURVE:
				tempElement = gcnew Curve(color, firstPoint, e->Location);
				break;*/
			case ElementType::ELLIPSE:
				tempElement = gcnew Ellipse(color, firstPoint, e->Location);
				break;
			}
			Invalidate();
		}
		else if (mode == Mode::Normal)
		{
			Element^ element(sketch->HitElement(e->Location));
			if (highlightedElement == element)
				return;
			if (highlightedElement)
			{
				Invalidate(highlightedElement->bound);
				highlightedElement->highlighted = false;
				highlightedElement = nullptr;
			}
			highlightedElement = element;
			if (highlightedElement)
			{
				highlightedElement->highlighted = true;
				Invalidate(highlightedElement->bound);
			}
			Update();
		}
		else if (mode == Mode::Move && e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			if (highlightedElement)
			{
				Invalidate(highlightedElement->bound);
				highlightedElement->Move(e->X - firstPoint.X,e->Y - firstPoint.Y);
				firstPoint = e->Location;
				Invalidate(highlightedElement->bound);
				Update();
			}
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (drawing)
		{
			if (tempElement)
				Invalidate(tempElement->bound);
			if (elementType == ElementType::CURVE)
			{
				tempElement = gcnew Curve(color, firstPoint, e->Location);
			}
			Invalidate();
		}

		if (!drawing)
		{
			mode = Mode::Normal;
			return;
		}
		if (tempElement)
		{
			sketch += tempElement;
			tempElement = nullptr;
			Invalidate();
		}
		drawing = false;
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		Graphics^ g = e->Graphics;
		sketch->Draw(g);
		if (tempElement != nullptr)
		{
			tempElement->Draw(g);
		}
	}

	private: System::Void ellipseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		elementType = ElementType::ELLIPSE;
		SetElementTypeButtonsState();
	}
			 
	private: System::Void deleteContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (highlightedElement)
		{
			sketch -= highlightedElement;
			Invalidate(highlightedElement->bound);
			highlightedElement = nullptr;
			Update();
		}
	}
	private: System::Void sendToBackContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (highlightedElement)
		{
			sketch -= highlightedElement;
			sketch->push_front(highlightedElement);
			highlightedElement->highlighted = false;
			Invalidate(highlightedElement->bound);
			highlightedElement = nullptr;
			Update();
		}
	}
	private: System::Void cleanContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		sketch=gcnew Sketch();
		Invalidate();
		Update();
	}
	private: System::Void contextMenuStrip1_Opening_1(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
	{
		contextMenuStrip1->Items->Clear();
		if (highlightedElement)
		{
			contextMenuStrip1->Items->Add(moveContextMenuItem);
			contextMenuStrip1->Items->Add(deleteContextMenuItem);
			contextMenuStrip1->Items->Add(sendToBackContextMenuItem);
		}
		else
		{
			contextMenuStrip1->Items->Add(lineContextMenuItem);
			contextMenuStrip1->Items->Add(rectangleContextMenuItem);
			contextMenuStrip1->Items->Add(circleContextMenuItem);
			contextMenuStrip1->Items->Add(curveContextMenuItem);
			contextMenuStrip1->Items->Add(contextSeparator);
			contextMenuStrip1->Items->Add(blackContextMenuItem);
			contextMenuStrip1->Items->Add(redContextMenuItem);
			contextMenuStrip1->Items->Add(greenContextMenuItem);
			contextMenuStrip1->Items->Add(blueContextMenuItem);
			contextMenuStrip1->Items->Add(cleanToolStripMenuItem);
			lineContextMenuItem->Checked = elementType == ElementType::LINE;
			rectangleContextMenuItem->Checked = elementType == ElementType::RECTANGLE;
			circleContextMenuItem->Checked = elementType == ElementType::CIRCLE;
			curveContextMenuItem->Checked = elementType == ElementType::CURVE;
			blackContextMenuItem->Checked = color == Color::Black;
			redContextMenuItem->Checked = color == Color::Red;
			greenContextMenuItem->Checked = color == Color::Green;
			blueContextMenuItem->Checked = color == Color::Blue;
		}
	}



private: System::Void elementToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
}

