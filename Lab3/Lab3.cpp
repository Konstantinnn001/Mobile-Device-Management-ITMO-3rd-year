#include <PDF/PDFNet.h>
#include <PDF/PDFDoc.h>
#include <PDF/PageSet.h>
#include <PDF/Stamper.h>
#include <PDF/Image.h>
#include <iostream>
#include "Mobile.cpp"
#include "Mobile2.cpp"
#include <math.h>


using namespace std;
using namespace pdftron;
using namespace Common;
using namespace SDF;
using namespace PDF;


	
	int main(int argc, char* argv[])
	{
		int ret = 0;
		string input_filename = "Blank.pdf";
		string output_filename = "Output.pdf";

		PDFNet::Initialize();
		main1();
		main2();
		
		try
		{
			pdftron::PDF::PDFDoc doc((input_filename).c_str());
			doc.InitSecurityHandler();
			Stamper s(Stamper::e_relative_scale, 0, 0);
			s.SetTextAlignment(Stamper::e_align_left);
			s.SetSize(Stamper::e_font_size, 10, -1);
			s.SetPosition(-184, 374);
			ColorPt black(0, 0, 0);
			s.SetFontColor(black);
			wstring abc = L"ПАО \"Дальневосточный банк\", г. Иркутск ";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(72, 374);
			abc = L"492478614";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));
			
			s.SetPosition(95, 360);
			abc = L"1547625891405301497";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(95, 337);
			abc = L"4620154789350120014";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-212, 337);
			abc = L"1504239048";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-72, 337);
			abc = L"1570364089";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));
			
			s.SetPosition(-228, 324);
			abc = L"ООО \"BOBAH inc.\"";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetSize(Stamper::e_font_size, 14, -1);
			s.SetPosition(-130, 271);
			abc = L"39";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-90, 271);
			abc = L"01.02";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-40, 271);
			abc = L"20";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetSize(Stamper::e_font_size, 12, -1);
			s.SetPosition(-5, 230);
			abc = L"ООО \"BOBAH inc.\", ИНН 1504239048, КПП 1570364089, 183590, г. Санкт-Петербург,\n ул. Пушкина, дом №34, корпус 2, офис 13";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(8, 196);
			abc = L"ООО \"OBIT TELECOM\", ИНН 1503949521, КПП 1596548215, 139480, г. Санкт-Петербург,\n ул. Есенина, дом №91, корпус 6, офис 24";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-134, 168);
			abc = L"№45910348 от 25.01.2020";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetSize(Stamper::e_font_size, 10, -1);
			s.SetPosition(-118, 131);
			abc = L"Оплата услуг интернет и мобильной связи за январь 2020 года";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(106, 131);
			string abc1;
			abc1 = to_string(sum+price);
			s.StampText(doc, abc1, PageSet(1, doc.GetPageCount()));

			s.SetPosition(170, 131);
			s.StampText(doc, abc1, PageSet(1, doc.GetPageCount()));

			s.SetPosition(170, 77);
			s.StampText(doc, abc1, PageSet(1, doc.GetPageCount()));

			s.SetPosition(170, 52);
			s.StampText(doc, abc1, PageSet(1, doc.GetPageCount()));

			s.SetPosition(168, 65);
			abc1 = to_string((sum + price)*0.2);
			s.StampText(doc, abc1, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-145, 38);
			abc = L"1, на сумму ", to_string(sum+price), "руб.";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-94, 38);
			abc1 = to_string(sum + price);
			s.StampText(doc, abc1, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-60, 38);
			abc = L"руб.";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-60, 28);
			abc = L"Три тысячи семьсот пять рублей двадцать восемь копеек";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(-20, -76);
			abc = L"Коробкин Л.С.";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			s.SetPosition(180, -76);
			abc = L"Банкин С.П.";
			s.StampText(doc, abc, PageSet(1, doc.GetPageCount()));

			doc.Save(output_filename, SDFDoc::e_linearized, NULL);
		}
		catch (Common::Exception& e)
		{
			std::cout << e << endl;
			ret = 1;
		}
		catch (...)
		{
			cout << "Unknown Exception" << endl;
			ret = 1;
		}

		cout << "Final file is Output.pdf\n";

		system("pause");

		PDFNet::Terminate();
		return ret;
	}