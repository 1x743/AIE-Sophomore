#pragma once
#include "CameraForm.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

namespace My6610110096 {
    using namespace System::Runtime::InteropServices;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        // Enum class to represent the drawing state
        enum class DrawState {
            NotDrawing,
            DrawLine, DrawingLine,
            DrawEllipse, DrawingEllipse
        } drawState;

        // Variables for drawing functionality
        System::Drawing::Point^ startPoint; // Starting point of the drawing
    private: System::Windows::Forms::Panel^ pictureBoxPanel;
    private: System::Windows::Forms::ToolStripButton^ toolStripButton6;
           Bitmap^ tmpImage;                  // Temporary image used for drawing

    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            this->Text = L"S6610110096";
            drawState = DrawState::NotDrawing; // Initialize to the default state
            startPoint = nullptr;
            tmpImage = nullptr;
            //TODO: Add the constructor code here
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
            delete image;
        }

    private:
        Bitmap^ bmp;
        cv::Mat* image = new cv::Mat();
        System::Windows::Forms::ToolStripContainer^ toolStripContainer;
        System::Windows::Forms::MenuStrip^ menuStrip;
        System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ openFileMenu;
        System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
        System::Diagnostics::EventLog^ eventLog1;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
    private: System::Windows::Forms::PictureBox^ pictureBox;
    private: System::Windows::Forms::ToolStripMenuItem^ imageToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ drawLineToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ drawEllipseToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ convertHSVToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ saveFileMenu;
    private: System::Windows::Forms::ToolStripMenuItem^ saveAsFileMenu;


    private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
    private: System::Windows::Forms::ToolStrip^ toolStrip;
    private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
    private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
    private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
    private: System::Windows::Forms::StatusStrip^ statusStrip;
    private: System::Windows::Forms::ToolStripStatusLabel^ statusLabel;
    private: System::Windows::Forms::ToolStripStatusLabel^ pixelPointLabel;
    private: System::Windows::Forms::ToolStripStatusLabel^ pixelColorLabel;
    private: System::Windows::Forms::ToolStripStatusLabel^ imageSizeLabel;

    private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
    private: System::Windows::Forms::ToolStripButton^ toolStripButton5;







    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->toolStripContainer = (gcnew System::Windows::Forms::ToolStripContainer());
            this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
            this->statusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->pixelPointLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->pixelColorLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->imageSizeLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->pictureBoxPanel = (gcnew System::Windows::Forms::Panel());
            this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
            this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
            this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->openFileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->saveFileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->saveAsFileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->imageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->drawLineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->drawEllipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->convertHSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
            this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
            this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
            this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
            this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
            this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
            this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
            this->eventLog1 = (gcnew System::Diagnostics::EventLog());
            this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
            this->toolStripContainer->BottomToolStripPanel->SuspendLayout();
            this->toolStripContainer->ContentPanel->SuspendLayout();
            this->toolStripContainer->TopToolStripPanel->SuspendLayout();
            this->toolStripContainer->SuspendLayout();
            this->statusStrip->SuspendLayout();
            this->pictureBoxPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
            this->menuStrip->SuspendLayout();
            this->toolStrip->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
            this->SuspendLayout();
            // 
            // toolStripContainer
            // 
            // 
            // toolStripContainer.BottomToolStripPanel
            // 
            this->toolStripContainer->BottomToolStripPanel->Controls->Add(this->statusStrip);
            // 
            // toolStripContainer.ContentPanel
            // 
            this->toolStripContainer->ContentPanel->Controls->Add(this->pictureBoxPanel);
            this->toolStripContainer->ContentPanel->Size = System::Drawing::Size(421, 332);
            this->toolStripContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->toolStripContainer->Location = System::Drawing::Point(0, 0);
            this->toolStripContainer->Name = L"toolStripContainer";
            this->toolStripContainer->Size = System::Drawing::Size(421, 403);
            this->toolStripContainer->TabIndex = 0;
            this->toolStripContainer->Text = L"toolStripContainer";
            // 
            // toolStripContainer.TopToolStripPanel
            // 
            this->toolStripContainer->TopToolStripPanel->Controls->Add(this->menuStrip);
            this->toolStripContainer->TopToolStripPanel->Controls->Add(this->toolStrip);
            // 
            // statusStrip
            // 
            this->statusStrip->Dock = System::Windows::Forms::DockStyle::None;
            this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
                this->pixelPointLabel,
                    this->statusLabel, this->pixelColorLabel, this->imageSizeLabel
            });
            this->statusStrip->Location = System::Drawing::Point(0, 0);
            this->statusStrip->Name = L"statusStrip";
            this->statusStrip->Size = System::Drawing::Size(421, 22);
            this->statusStrip->TabIndex = 0;
            // 
            // statusLabel
            // 
            this->statusLabel->Name = L"statusLabel";
            this->statusLabel->Size = System::Drawing::Size(208, 17);
            this->statusLabel->Spring = true;
            this->statusLabel->Text = L"toolStripStatusLabel1";
            // 
            // pixelPointLabel
            // 
            this->pixelPointLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pixelPointLabel.Image")));
            this->pixelPointLabel->Name = L"pixelPointLabel";
            this->pixelPointLabel->Size = System::Drawing::Size(40, 17);
            this->pixelPointLabel->Text = L"X,Y";
            this->pixelPointLabel->Visible = false;
            // 
            // pixelColorLabel
            // 
            this->pixelColorLabel->Name = L"pixelColorLabel";
            this->pixelColorLabel->Size = System::Drawing::Size(79, 17);
            this->pixelColorLabel->Text = L"RGB=[R, G, B]";
            this->pixelColorLabel->Visible = false;
            // 
            // imageSizeLabel
            // 
            this->imageSizeLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageSizeLabel.Image")));
            this->imageSizeLabel->Name = L"imageSizeLabel";
            this->imageSizeLabel->Size = System::Drawing::Size(48, 17);
            this->imageSizeLabel->Text = L"WxH";
            this->imageSizeLabel->Visible = false;
            // 
            // pictureBoxPanel
            // 
            this->pictureBoxPanel->AutoScroll = true;
            this->pictureBoxPanel->Controls->Add(this->pictureBox);
            this->pictureBoxPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pictureBoxPanel->Location = System::Drawing::Point(0, 0);
            this->pictureBoxPanel->Name = L"pictureBoxPanel";
            this->pictureBoxPanel->Size = System::Drawing::Size(421, 332);
            this->pictureBoxPanel->TabIndex = 1;
            // 
            // pictureBox
            // 
            this->pictureBox->Location = System::Drawing::Point(0, 0);
            this->pictureBox->Name = L"pictureBox";
            this->pictureBox->Size = System::Drawing::Size(0, 0);
            this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
            this->pictureBox->TabIndex = 0;
            this->pictureBox->TabStop = false;
            this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseDown_1);
            this->pictureBox->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox_MouseEnter_1);
            this->pictureBox->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox_MouseLeave_1);
            this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseMove_1);
            this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseUp_1);
            // 
            // menuStrip
            // 
            this->menuStrip->Dock = System::Windows::Forms::DockStyle::None;
            this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->fileToolStripMenuItem,
                    this->imageToolStripMenuItem
            });
            this->menuStrip->Location = System::Drawing::Point(0, 0);
            this->menuStrip->Name = L"menuStrip";
            this->menuStrip->Size = System::Drawing::Size(421, 24);
            this->menuStrip->TabIndex = 0;
            this->menuStrip->Text = L"menuStrip";
            // 
            // fileToolStripMenuItem
            // 
            this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
                this->openFileMenu,
                    this->saveFileMenu, this->saveAsFileMenu, this->exitToolStripMenuItem
            });
            this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
            this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
            this->fileToolStripMenuItem->Text = L"File";
            // 
            // openFileMenu
            // 
            this->openFileMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openFileMenu.Image")));
            this->openFileMenu->Name = L"openFileMenu";
            this->openFileMenu->Size = System::Drawing::Size(114, 22);
            this->openFileMenu->Text = L"Open";
            this->openFileMenu->Click += gcnew System::EventHandler(this, &MyForm::openFileMenu_Click);
            // 
            // saveFileMenu
            // 
            this->saveFileMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveFileMenu.Image")));
            this->saveFileMenu->Name = L"saveFileMenu";
            this->saveFileMenu->Size = System::Drawing::Size(114, 22);
            this->saveFileMenu->Text = L"Save";
            this->saveFileMenu->Click += gcnew System::EventHandler(this, &MyForm::saveFileMenu_Click);
            // 
            // saveAsFileMenu
            // 
            this->saveAsFileMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveAsFileMenu.Image")));
            this->saveAsFileMenu->Name = L"saveAsFileMenu";
            this->saveAsFileMenu->Size = System::Drawing::Size(114, 22);
            this->saveAsFileMenu->Text = L"Save As";
            this->saveAsFileMenu->Click += gcnew System::EventHandler(this, &MyForm::saveAsFileMenu_Click);
            // 
            // exitToolStripMenuItem
            // 
            this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.Image")));
            this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
            this->exitToolStripMenuItem->Size = System::Drawing::Size(114, 22);
            this->exitToolStripMenuItem->Text = L"Exit";
            this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
            // 
            // imageToolStripMenuItem
            // 
            this->imageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                this->drawLineToolStripMenuItem,
                    this->drawEllipseToolStripMenuItem, this->convertHSVToolStripMenuItem
            });
            this->imageToolStripMenuItem->Name = L"imageToolStripMenuItem";
            this->imageToolStripMenuItem->Size = System::Drawing::Size(52, 20);
            this->imageToolStripMenuItem->Text = L"Image";
            this->imageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::imageToolStripMenuItem_Click);
            // 
            // drawLineToolStripMenuItem
            // 
            this->drawLineToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"drawLineToolStripMenuItem.Image")));
            this->drawLineToolStripMenuItem->Name = L"drawLineToolStripMenuItem";
            this->drawLineToolStripMenuItem->Size = System::Drawing::Size(155, 22);
            this->drawLineToolStripMenuItem->Text = L"Draw Line";
            this->drawLineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawLineToolStripMenuItem_Click);
            // 
            // drawEllipseToolStripMenuItem
            // 
            this->drawEllipseToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"drawEllipseToolStripMenuItem.Image")));
            this->drawEllipseToolStripMenuItem->Name = L"drawEllipseToolStripMenuItem";
            this->drawEllipseToolStripMenuItem->Size = System::Drawing::Size(155, 22);
            this->drawEllipseToolStripMenuItem->Text = L"Draw Ellipse";
            this->drawEllipseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawEllipseToolStripMenuItem_Click);
            // 
            // convertHSVToolStripMenuItem
            // 
            this->convertHSVToolStripMenuItem->Name = L"convertHSVToolStripMenuItem";
            this->convertHSVToolStripMenuItem->Size = System::Drawing::Size(155, 22);
            this->convertHSVToolStripMenuItem->Text = L"Convert to HSV";
            this->convertHSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::convertHSVToolStripMenuItem_Click);
            // 
            // toolStrip
            // 
            this->toolStrip->Dock = System::Windows::Forms::DockStyle::None;
            this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
                this->toolStripButton1,
                    this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton5, this->toolStripButton6
            });
            this->toolStrip->Location = System::Drawing::Point(3, 24);
            this->toolStrip->Name = L"toolStrip";
            this->toolStrip->Size = System::Drawing::Size(150, 25);
            this->toolStrip->TabIndex = 1;
            // 
            // toolStripButton1
            // 
            this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
            this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->toolStripButton1->Name = L"toolStripButton1";
            this->toolStripButton1->Size = System::Drawing::Size(23, 22);
            this->toolStripButton1->Text = L"Open";
            this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton1_Click);
            // 
            // toolStripButton2
            // 
            this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
            this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->toolStripButton2->Name = L"toolStripButton2";
            this->toolStripButton2->Size = System::Drawing::Size(23, 22);
            this->toolStripButton2->Text = L"Save";
            this->toolStripButton2->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton2_Click);
            // 
            // toolStripButton3
            // 
            this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
            this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->toolStripButton3->Name = L"toolStripButton3";
            this->toolStripButton3->Size = System::Drawing::Size(23, 22);
            this->toolStripButton3->Text = L"SaveAs";
            this->toolStripButton3->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton3_Click);
            // 
            // toolStripButton4
            // 
            this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
            this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->toolStripButton4->Name = L"toolStripButton4";
            this->toolStripButton4->Size = System::Drawing::Size(23, 22);
            this->toolStripButton4->Text = L"Draw Line";
            this->toolStripButton4->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton4_Click);
            // 
            // toolStripButton5
            // 
            this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
            this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->toolStripButton5->Name = L"toolStripButton5";
            this->toolStripButton5->Size = System::Drawing::Size(23, 22);
            this->toolStripButton5->Text = L"Draw Ellipse";
            this->toolStripButton5->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton5_Click);
            // 
            // toolStripButton6
            // 
            this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
            this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->toolStripButton6->Name = L"toolStripButton6";
            this->toolStripButton6->Size = System::Drawing::Size(23, 22);
            this->toolStripButton6->Text = L"toolStripButton6";
            this->toolStripButton6->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton6_Click);
            // 
            // eventLog1
            // 
            this->eventLog1->SynchronizingObject = this;
            // 
            // openFileDialog
            // 
            this->openFileDialog->FileName = L"openFileDialog";
            this->openFileDialog->Filter = L"Image files|*.jpg;*.png";
            // 
            // saveFileDialog
            // 
            this->saveFileDialog->DefaultExt = L"png";
            this->saveFileDialog->Filter = L"Image files|*.jpg;*.png";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(421, 403);
            this->Controls->Add(this->toolStripContainer);
            this->MainMenuStrip = this->menuStrip;
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->toolStripContainer->BottomToolStripPanel->ResumeLayout(false);
            this->toolStripContainer->BottomToolStripPanel->PerformLayout();
            this->toolStripContainer->ContentPanel->ResumeLayout(false);
            this->toolStripContainer->TopToolStripPanel->ResumeLayout(false);
            this->toolStripContainer->TopToolStripPanel->PerformLayout();
            this->toolStripContainer->ResumeLayout(false);
            this->toolStripContainer->PerformLayout();
            this->statusStrip->ResumeLayout(false);
            this->statusStrip->PerformLayout();
            this->pictureBoxPanel->ResumeLayout(false);
            this->pictureBoxPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
            this->menuStrip->ResumeLayout(false);
            this->menuStrip->PerformLayout();
            this->toolStrip->ResumeLayout(false);
            this->toolStrip->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}

    private: System::Void openFileMenu_Click(System::Object^ sender, System::EventArgs^ e) {
        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            Bitmap^ image = gcnew Bitmap(openFileDialog->FileName);
            // Convert image to 24 bits RGB
            bmp = gcnew Bitmap(image->Size.Width, image->Size.Height,
                Imaging::PixelFormat::Format24bppRgb);

            bmp->SetResolution(image->HorizontalResolution, image->VerticalResolution);
            Graphics^ g = Graphics::FromImage(bmp);
            g->DrawImage(image, 0, 0);
            delete image;
            pictureBox->Image = bmp;
            imageSizeLabel->Text = System::String::Format("{0}x{1}", bmp->Width, bmp->Height);
            imageSizeLabel->Visible = true;
        }
    }

           System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
               Close();
           }

    private: System::Void pictureBox_MouseEnter_1(System::Object^ sender, System::EventArgs^ e) {
        pixelPointLabel->Visible = true;
        pixelColorLabel->Visible = true;
    }

    private: System::Void pictureBox_MouseLeave_1(System::Object^ sender, System::EventArgs^ e) {
        pixelPointLabel->Visible = false;
        pixelColorLabel->Visible = false;
    }
    private: System::Void drawLineToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

        if (bmp != nullptr) {
            drawState = DrawState::DrawLine;
            Cursor = Cursors::Cross;
        }
    }
    private: System::Void drawEllipseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

        if (bmp != nullptr) {
            drawState = DrawState::DrawEllipse;
            Cursor = Cursors::Cross;
        }
    }

    private: System::Void pictureBox_MouseMove_1(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (bmp == nullptr) return;
        if ((e->X >= 0) && (e->X < bmp->Width) && (e->Y >= 0) && (e->Y < bmp->Height)) {
            pixelPointLabel->Text = System::String::Format("{0}, {1}", e->X, e->Y);
            Color c = bmp->GetPixel(e->X, e->Y);
            pixelColorLabel->Text = System::String::Format("RGB=[{0}, {1}, {2}]", c.R, c.G, c.B);

        }

        // Handle drawing logic for line or ellipse
        if ((drawState == DrawState::DrawingLine) || (drawState == DrawState::DrawingEllipse)) {
            if (tmpImage != nullptr) delete tmpImage;
            tmpImage = (Bitmap^)bmp->Clone();
            // Lock Bitmap Bits ...
            Imaging::BitmapData^ bmpData = tmpImage->LockBits(
                System::Drawing::Rectangle(0, 0, tmpImage->Width, tmpImage->Height),
                Imaging::ImageLockMode::ReadWrite,
                Imaging::PixelFormat::Format24bppRgb
            );

            // Access raw image data using OpenCV
            cv::Mat image(tmpImage->Height, tmpImage->Width, CV_8UC3, bmpData->Scan0.ToPointer());

            // Do OpenCV function
            switch (drawState) {
            case DrawState::DrawingLine:
                line(image, cv::Point(startPoint->X, startPoint->Y), cv::Point(e->X, e->Y), CV_RGB(0, 255, 0));
                break;
            case DrawState::DrawingEllipse:
                int dx = Math::Abs(startPoint->X - e->X);
                int dy = Math::Abs(startPoint->Y - e->Y);
                ellipse(image, cv::Point(startPoint->X, startPoint->Y),
                    cv::Size(dx, dy),
                    Math::Atan2(dy, dx), 0, 360,
                    CV_RGB(0, 255, 0));
                break;
            }
            // Unlock Bitmap Bits
            tmpImage->UnlockBits(bmpData);
            pictureBox->Image = tmpImage; // Show result
        }
    }
    private: System::Void pictureBox_MouseDown_1(System::Object^ sender, MouseEventArgs^ e) {

        if (bmp != nullptr) {
            switch (drawState) {
            case DrawState::DrawLine:
            case DrawState::DrawEllipse:
                startPoint = gcnew System::Drawing::Point(e->X, e->Y);
                if (drawState == DrawState::DrawLine)
                    drawState = DrawState::DrawingLine;
                else
                    drawState = DrawState::DrawingEllipse;
            }
        }
    }
    private: System::Void pictureBox_MouseUp_1(System::Object^ sender, MouseEventArgs^ e) {

        if ((drawState == DrawState::DrawingLine) || (drawState == DrawState::DrawingEllipse)) {

            delete startPoint;
            startPoint = nullptr;
            delete bmp;
            bmp = tmpImage;
            tmpImage = nullptr;
            drawState = DrawState::NotDrawing;
            Cursor = Cursors::Default;
        }
    }
    private: System::Void imageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        // This method is currently empty, but you can add any functionality you need here.
    }
    private: System::Void convertHSVToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        if (bmp == nullptr) {
            MessageBox::Show("No image loaded. Please load an image first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        // Lock Bitmap Bits
        Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
        System::Drawing::Imaging::BitmapData^ bmpData =
            bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat);
        // Using OpenCV: Create Image with data pointer
        cv::Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);
        // Convert BGR to HSV
        cv::Mat hsvImage;
        cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);
        // Copy HSV image back to Bitmap
        std::memcpy(bmpData->Scan0.ToPointer(), hsvImage.data, bmp->Height * bmpData->Stride);
        // Unlock Bitmap Bits
        bmp->UnlockBits(bmpData);

        // Update PictureBox
        pictureBox->Image = bmp;
    }

    private: System::Void saveFileMenu_Click(System::Object^ sender, System::EventArgs^ e) {
        if (bmp != nullptr) {
            bmp->Save(openFileDialog->FileName);
        }
    }

    private: System::Void saveAsFileMenu_Click(System::Object^ sender, System::EventArgs^ e) {
        if ((bmp != nullptr) && (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)) {
            bmp->Save(saveFileDialog->FileName);
        }
    }

    private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            Bitmap^ image = gcnew Bitmap(openFileDialog->FileName);
            bmp = gcnew Bitmap(image->Size.Width, image->Size.Height, Imaging::PixelFormat::Format24bppRgb);
            bmp->SetResolution(image->HorizontalResolution, image->VerticalResolution);
            Graphics^ g = Graphics::FromImage(bmp);
            g->DrawImage(image, 0, 0);
            delete image;
            pictureBox->Image = bmp;
        }
    }

    private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
        if (bmp != nullptr) {
            bmp->Save(openFileDialog->FileName);
        }
    }

    private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
        if ((bmp != nullptr) && (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)) {
            bmp->Save(saveFileDialog->FileName);
        }
    }

    private: System::Void toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
        if (bmp != nullptr) {

            drawState = DrawState::DrawLine;
            Cursor = Cursors::Cross;

        }
    }
    private: System::Void toolStripButton5_Click(System::Object^ sender, System::EventArgs^ e) {
        if (bmp != nullptr) {

            drawState = DrawState::DrawEllipse;
            Cursor = Cursors::Cross;

        }
    }
private: System::Void toolStripButton6_Click(System::Object^ sender, System::EventArgs^ e) {
    CameraForm^ cameraform = gcnew CameraForm();
    cameraform->ShowDialog();
}
};
}