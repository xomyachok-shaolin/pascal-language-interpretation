using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace CW_PLT
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            richTextBox1.AllowDrop = true;
            richTextBox1.DragDrop += new DragEventHandler(RichTextBox1_DragDrop);
            saveFileDialog1.Filter = "|*.st";
            string filename = saveFileDialog1.FileName;
        }
        private void RichTextBox1_DragDrop(object sender, DragEventArgs e)
        {
            var data = e.Data.GetData(DataFormats.FileDrop);
            if (data != null)
            {
                string[] objects = (string[])e.Data.GetData(DataFormats.FileDrop);
                // В objects хранятся пути к папкам и файлам
                richTextBox1.Text = null;
                for (int i = 0; i < objects.Length; i++)
                {
                    string fileText = File.ReadAllText(objects[i]);
                    richTextBox1.Text = fileText;
                }
            }
        }

        private void сохранитьКакToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            string filename = saveFileDialog1.FileName;
            File.WriteAllText(filename, richTextBox1.Text);
            MessageBox.Show("Файл сохранен!");


        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            string filename = openFileDialog1.FileName;
            string fileText = File.ReadAllText(filename);
            richTextBox1.Text = fileText;
            File.WriteAllText(filename, richTextBox1.Text);
            MessageBox.Show("Файл открыт!");
        }

        private void настройкаШрифтаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowDialog();
            richTextBox1.Font = fontDialog1.Font;
            richTextBox2.Font = fontDialog1.Font;
            richTextBox3.Font = fontDialog1.Font;
        }

        private void настройкаФонаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            richTextBox1.BackColor = colorDialog1.Color;
            richTextBox2.BackColor = colorDialog1.Color;
            richTextBox3.BackColor = colorDialog1.Color;
        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string filename = openFileDialog1.FileName;
            if (filename.Length < 1)
                if (saveFileDialog1.ShowDialog() == DialogResult.Cancel)
                    return;

            File.WriteAllText(filename, richTextBox1.Text);
            MessageBox.Show("Файл сохранен!");
        }

        private void выполнитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            File.WriteAllText("1.st", richTextBox1.Text);
            richTextBox1.Text = File.ReadAllText("1.st");

            Process.Start("simplet.exe", "/?");//cmd,argument
            Thread.Sleep(1500);

            if (File.Exists("poliz") && File.Exists("response"))
            {
                richTextBox3.Text = File.ReadAllText("poliz");
                string out_str = File.ReadAllText("response");

                if (File.Exists("lexan"))
                    out_str += File.ReadAllText("lexan");


                richTextBox2.Text = out_str;

                File.Delete("response");
                File.Delete("poliz");
                if (File.Exists("lexan"))
                    File.Delete("lexan");
                // File.Delete("1.st");
            }
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            richTextBox1.Text = "begin\n\twrite(\"Hello World!\");\nend.";
            Font defaultFont = new Font("Microsoft Sans Serif", 16);
            fontDialog1.Font = defaultFont;
            richTextBox1.Font = defaultFont;
            richTextBox2.Font = defaultFont;
            richTextBox3.Font = defaultFont;

        }
    }
}
