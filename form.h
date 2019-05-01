#pragma once

#include <vector>
#include "avl_tree.h"
#include <iostream>
#include <ctime>
#include "source.hpp"

namespace avltreewinforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	vector<avl_tree> trees;

	public ref class form : public System::Windows::Forms::Form
	{
	public:
		form(void)
		{
			InitializeComponent();
			srand(time(unsigned int(0)));
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox;
	protected:

	private: System::Windows::Forms::ComboBox^ middleBox;
	protected:

	private: System::Windows::Forms::ComboBox^ rightBox;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::Splitter^ splitter1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->middleBox = (gcnew System::Windows::Forms::ComboBox());
			this->rightBox = (gcnew System::Windows::Forms::ComboBox());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(8, 7);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(789, 509);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->Click += gcnew System::EventHandler(this, &form::PictureBox_Click);
			// 
			// middleBox
			// 
			this->middleBox->FormattingEnabled = true;
			this->middleBox->Location = System::Drawing::Point(803, 12);
			this->middleBox->Name = L"middleBox";
			this->middleBox->Size = System::Drawing::Size(233, 24);
			this->middleBox->TabIndex = 1;
			this->middleBox->SelectedIndexChanged += gcnew System::EventHandler(this, &form::MiddleBox_SelectedIndexChanged);
			// 
			// rightBox
			// 
			this->rightBox->FormattingEnabled = true;
			this->rightBox->Location = System::Drawing::Point(1042, 12);
			this->rightBox->Name = L"rightBox";
			this->rightBox->Size = System::Drawing::Size(138, 24);
			this->rightBox->TabIndex = 2;
			this->rightBox->SelectedIndexChanged += gcnew System::EventHandler(this, &form::RightBox_SelectedIndexChanged);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(1186, 12);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(121, 22);
			this->textBox->TabIndex = 3;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &form::TextBox_TextChanged);
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 516);
			this->splitter1->TabIndex = 4;
			this->splitter1->TabStop = false;
			// 
			// form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1319, 516);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->rightBox);
			this->Controls->Add(this->middleBox);
			this->Controls->Add(this->pictureBox);
			this->Name = L"form";
			this->Text = L"form";
			this->Load += gcnew System::EventHandler(this, &form::Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "by UnitedTimur (c)";
		this->BackColor = Color::Gray;
		
		//middleBox
		middleBox->Items->Add("Create random size tree");
		middleBox->Items->Add("Create tree with root");
		middleBox->Items->Add("Out all trees in console");
		middleBox->Items->Add("Out current tree in console");
		middleBox->Items->Add("Add number in current tree");
		middleBox->Items->Add("Delete number in current tree");
		middleBox->Items->Add("Clear the console");
		middleBox->Items->Add("Paint current tree");

		//textBox
		textBox->Text = Convert::ToString(0);
	}
	private: System::Void MiddleBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		static int i = 0;

			switch (middleBox->SelectedIndex)
			{
			case 0:
				{
					cout << "// Method 'Create random size tree' //" << endl;

					avl_tree tree;

					for (auto i = 0; i < Convert::ToInt64(textBox->Text); ++i)
					{
						tree.push(rand() % 99 - 45);
					}

					trees.push_back(tree);

					rightBox->Items->Add("Tree " + ++i);

					break;
				}
			case 1:
				{
					cout << "// Method 'Create tree with root' //" << endl;

					avl_tree tree;

					tree.push(Convert::ToInt64(textBox->Text));

					trees.push_back(tree);

					rightBox->Items->Add("Tree " + ++i);

					break;
				}
			case 2:
				{
					cout << "// Method 'Out all trees in console' //" << endl;

					for (auto i = 0; i < trees.size(); ++i)
					{
						cout << "		// Tree " << i + 1 << " ---> " << trees[i] << endl;
					}

					break;
				}
			case 3:
				{
					cout << "// Method 'Out current tree'" << endl;

					for (auto i = 0; i < trees.size(); ++i)
					{
						if (i == rightBox->SelectedIndex)
						{
							cout << "		// Tree " << i + 1 << " ---> " << trees[i] << endl;
						}
					}

					break;
				}
			case 4:
				{
					cout << "// Method 'Add number in current tree' //" << endl;

					for (auto i = 0; i < trees.size(); ++i)
					{
						if (i == rightBox->SelectedIndex)
						{
							trees[i].push(Convert::ToInt64(textBox->Text));
						}
					}

					break;
				}
			case 5:
				{
					cout << "// Method 'Delete number in current tree' //" << endl;

					for (auto i = 0; i < trees.size(); ++i)
					{
						if (i == rightBox->SelectedIndex)
						{
							trees[i].pop(Convert::ToInt64(textBox->Text));
						}
					}

					break;
				}
			case 6:
				{
					system("cls");
					break;
				}
			case 7:
				{
					cout << "// Method 'Paint current tree' //" << endl;

					Graphics^ graph = pictureBox->CreateGraphics();
					Brush^ brushE = gcnew SolidBrush(Color::DarkRed);
					Brush^ brushT = gcnew SolidBrush(Color::White);
					String^ drawS;
					System::Drawing::Font^ drawF = gcnew System::Drawing::Font("Arial", 18);

					graph->Clear(Color::Gray);

					for (auto i = 0; i < trees.size(); ++i)
					{
						if (i == rightBox->SelectedIndex)
						{
							vector<int> tree = trees[i].post(trees[i].get_root());

							node* _node = trees[i].get_root();

							int left = 0, right = pictureBox->Width - 100;

							for (auto var : tree)
							{
								drawS = Convert::ToString(var);
								paint(graph, brushE, brushT, drawF, drawS, _node, left, right, 0);
								delete drawS;
							}
						}
					}

					delete graph;
					delete brushE;
					delete brushT;
					delete drawF;

					break;
				}
			}
	}
	private: System::Void RightBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void PictureBox_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
