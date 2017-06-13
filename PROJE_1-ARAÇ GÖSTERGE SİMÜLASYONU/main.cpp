#include <allegro.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

class yakit{
	protected:
		int yakit=6500;
	public:
		float degree_yakit=95;
		void yakitAzalt()
		{
			if(yakit>0 && degree_yakit>30)
			{
				yakit=yakit-0.01;
				degree_yakit=degree_yakit-0.01;
			}
		}
		float yakitDegeri()
		{
			return degree_yakit;
		}
		
};

class sinyal
{ 
	private:	
		bool sagSinyal=0,solSinyal=0,dortluSinyal=0;

	public:
		void sagSinyalSS()
		{
			solSinyal=0;
			dortluSinyal=0;
		
			if(sagSinyal==0)
				sagSinyal=1;
			else if(sagSinyal==1)
				sagSinyal=0;
		}
		void solSinyalSS()
		{
			sagSinyal=0;
			dortluSinyal=0;
		
			if(solSinyal==0)
				solSinyal=1;
			else if(solSinyal==1)
				solSinyal=0;
		}
		void dortluSinyalSS()
		{
			sagSinyal=0;
			solSinyal=0;
		
			if(dortluSinyal==0)
				dortluSinyal=1;
			else if(dortluSinyal==1)
				dortluSinyal=0;
		}
	
		bool sagSinyalDegeri()
		{return sagSinyal;}
		bool solSinyalDegeri()
		{return solSinyal;}
		bool dortluSinyalDegeri()
		{return dortluSinyal;}
	
 };

 class FarveLambalar
 { 
			private:	
				bool uzunFar=0,kisaFar=0,onSisFar=0,parkLambalari=0,arkaSisLambalari=0,yagBasinci=0,kemer=1,camRezistansi=0,kilitler=1;

			public:
				void uzunFarSS()
				{
					if(uzunFar==0)
					uzunFar=1;
					else if(uzunFar==1)
					uzunFar=0;
				}
				void kisaFarSS()
				{
					if(parkLambalari==0)
						parkLambalari=1;
						
					if(kisaFar==0)
						kisaFar=1;
					else if(kisaFar==1)
						kisaFar=0;
				}
				void onSisFarSS()
				{
						
					if(kisaFar==0)
						kisaFar==1;
						
					if(onSisFar==0)
						onSisFar=1;
					else if(onSisFar==1)
						onSisFar=0;
				}
				void parkLambalariSS()
				{
					if(parkLambalari==0)
						parkLambalari=1;
					else if(parkLambalari==1)
						parkLambalari=0;
				}
				void arkaSisLambalariSS()
				{
					if(kisaFar==0)
						kisaFar==1;
						
					if(arkaSisLambalari==0)
						arkaSisLambalari=1;
					else if(arkaSisLambalari==1)
						arkaSisLambalari=0;
				}
				void yagBasinciSS()
				{
					if(yagBasinci==0)
						yagBasinci=1;
				}
				void camRezistansiSS()
				{
					if(camRezistansi==1)
						camRezistansi=0;
					else if(camRezistansi==0)
						camRezistansi=1;
				}
				void kemerSS()
				{
					if(kemer==1)
						kemer=0;
					else if(kemer==0)
						kemer=1;
				}
				void kilitlerSS()
				{
					if(kilitler==1)
						kilitler=0;
					else if(kilitler==0)
						kilitler=1;
				}
				
				bool uzunFarDegeri()
				{return uzunFar;}
				bool kisaFarDegeri()
				{return kisaFar;}
				bool onSisFarDegeri()
				{return onSisFar;}
				bool parkLambalariDegeri()
				{return parkLambalari;}
				bool arkaSisLambalariDegeri()
				{return arkaSisLambalari;}
				bool yagBasinciDegeri()
				{return yagBasinci;}
				bool camRezistansiDegeri()
				{return camRezistansi;}
				bool kemerDegeri()
				{return kemer;}
				bool kilitlerDegeri()
				{return kilitler;}
	
};

class hizlanma: public yakit
{
	protected:
		float devir=0;
	   	int hararet=0;
	    float degree_devir=-13,degree_hiz=-13,degree_su=25;
	    
	public:
		float gkm=0;
		int vites=0;
		bool hizSabitleyici=0;
		float hiz=0;
		float km=0;
		bool parkFreni=1;
		
		void hizSabitleyiciSS()
		{
			
			if(hizSabitleyici==1 && degree_hiz>-13)
				{
					kmArttir();
					yakitAzalt();
					hararetArttir();
				}
			else if(hizSabitleyici==0)
					hizSabitleyici=1;		
				
		}
		
		void hizlan()
		{
			if(hizSabitleyici==0 && parkFreni==0 && degree_devir<=115 && yakitDegeri()>=32 && degree_su<95)
			{
					if(vites==0)
						vites=1;
			
					if(degree_devir>=-13 && degree_devir<=12)
						devir=0;
					else if(degree_devir>=13 && degree_devir<=38) 
						devir=1;
					else if(degree_devir>=39 && degree_devir<=64) 
						devir=2;	
					else if(degree_devir>=65 && degree_devir<=91) 
						devir=3;
					else if(degree_devir>=92)
						devir=4;
			
			
					if(degree_devir>=75 && vites <5)
					{
						degree_devir=40;
						devir=2;
						++vites;
					}	
			
					if(degree_devir<=115)
					{
						degree_devir=degree_devir+0.6;
						devir=devir+0.23;
						degree_hiz=degree_hiz+0.1*vites;
						hiz=hiz+0.161*vites;
					}
					
			}
			else if( degree_su>=95 || yakitDegeri()<=32 )
			{
				fren();
			}
			
			if(hizSabitleyici)
				hizSabitleyici=0;
			
			hararetArttir();
			yakitAzalt();
			kmArttir();
			
		}
		
		float hizDegeri()
		{
			return degree_hiz;
		}
		
		void fren()
		{
			if(hizSabitleyici==0)
			{
				if(vites==1 && degree_devir==-13)
					vites=0;
					
				if(degree_devir>=-13 && degree_devir<=12)
						devir=0;
				else if(degree_devir>=13 && degree_devir<=38) 
						devir=1;
				else if(degree_devir>=39 && degree_devir<=64) 
						devir=2;	
				else if(degree_devir>=65 && degree_devir<=91) 
						devir=3;
				else if(degree_devir>=92)
						devir=4;	
			
				if(degree_devir <= 40 && vites>1)
				{
					degree_devir=75;
					--vites;
				}
			
				if(degree_devir >= -13)
					{
						degree_devir=degree_devir-0.6;
						devir=devir-0.23;
					}
			
				if(degree_hiz >= -13)
					{
						degree_hiz=degree_hiz-0.1*(vites);
						hiz=hiz-0.161*vites;
					}
				
				if(degree_yakit>30 && degree_hiz >-13)	
					{
						degree_yakit=degree_yakit-0.01;
						yakit=yakit-0.1;
					}	
			
				if(degree_su>25 && (int)degree_devir==-13 && (int)degree_hiz==-13)
					hararetDusur();
			
				kmArttir();
			
			}
				
		}
		
		void parkFren()
		{
			if(hizSabitleyici==1)
			  	hizSabitleyiciSS();
			  
			if(parkFreni==0)
		 	{
		 		parkFreni=1;
		 	}
		 	
			else if(parkFreni==1)
		 	{
		 		fren();
		  		parkFreni=0;
		 	}
		 	
		 	if(degree_su>25 && (int)degree_devir==-13 && (int)degree_hiz==-13)
				hararetDusur();	
		} 
		
		void kmArttir()
		{
			if(hiz>0)
			{
				km+=hiz/1000;
				gkm+=hiz/1000;
			}
			
		}
		
		void kmSifirla()
		{
			gkm=0;
		}
		
		void hararetArttir()
		{
			if(degree_su < 60)
				degree_su=degree_su+0.1;
			
			if(hararet<90 && devir>1)
	 			hararet++;
	 			
	 		if(degree_su<=95  && degree_su>=60 && degree_devir>=110)
			 	degree_su=degree_su+0.1;	
		
		}
		
		void hararetDusur()
		{
			if(degree_su>=30)
	 			degree_su=degree_su-0.1;
		}
		
		float hararetDegeri()
		{
			return degree_su;
		}
		
		float devirDegeri()
		{
			return degree_devir;
		}
		
};

class araba : public sinyal , public FarveLambalar , public hizlanma
{
	
		string arabaIsim;
	public:
		araba(string isim)
		{
			arabaIsim=isim;
		}
		araba()
		{}

};



void Baslat() 
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 500, 0, 0);
	if (res != 0) {
	allegro_message(allegro_error);
	exit(-1);
	}
	install_timer();
	install_keyboard();
	install_mouse();

}
void Bitir() 
{
	clear_keybuf();
}

volatile int timer;
void incrementa_timer() { timer++; }   
END_OF_FUNCTION(incrementa_timer)

int main() 
{
	Baslat();
	
	araba a("bmw");
	
	install_timer();
	LOCK_FUNCTION(incrementa_timer);
	LOCK_VARIABLE(timer);
	install_int_ex(incrementa_timer,SECS_TO_TIMER(1));
	srand (time(NULL));
	
	BITMAP *oyunresim = create_bitmap(800,500);
	BITMAP *araresim = create_bitmap(800,500);							
	BITMAP *arkaplan = load_bitmap("gostergeler.bmp",NULL);
	BITMAP *ibre = load_bitmap("ibre.bmp",NULL);
	BITMAP *ibre2 = load_bitmap("ibre2.bmp",NULL);
	BITMAP *ibre3 = load_bitmap("ibre3.bmp",NULL);
	BITMAP *ibre4 = load_bitmap("ibre4.bmp",NULL);
	BITMAP *yakit = load_bitmap("yakit1.bmp",NULL);
	BITMAP *yag_basinci = load_bitmap("yagBasinci.bmp",NULL);
	BITMAP *el_freni = load_bitmap("el_freni.bmp",NULL);
	BITMAP *camRezistansi = load_bitmap("camRezistansi.bmp",NULL);
	BITMAP *kisaFar = load_bitmap("kisaFar.bmp",NULL);
	BITMAP *onSisFar = load_bitmap("onSisFar.bmp",NULL);
	BITMAP *arkaSisLambalari = load_bitmap("arkaSisLambasi.bmp",NULL);
	BITMAP *parkLambalari = load_bitmap("parkLambalari.bmp",NULL);
	BITMAP *uzunFar = load_bitmap("uzunFar.bmp",NULL);
	BITMAP *kemer = load_bitmap("kemer.bmp",NULL);
	BITMAP *kilitler = load_bitmap("kilitler.bmp",NULL);
	BITMAP *hararet = load_bitmap("hararet.bmp",NULL);
	BITMAP *hizSabitleyici = load_bitmap("hizSabitleyici1.bmp",NULL);
	BITMAP *sagSinyal = load_bitmap("sagSinyal.bmp",NULL);
	BITMAP *solSinyal = load_bitmap("solSinyal.bmp",NULL);
	BITMAP *dortluSinyal = load_bitmap("dortluSinyal.bmp",NULL);
	
	show_mouse(screen);
	
	while (!key[KEY_ESC]) 
	{
		blit(arkaplan,araresim,0,0,0,0,800,500);
		
		textprintf_ex(araresim,font,353,335,makecol(255,255,255),-1,"Vites:%d",a.vites);
		textprintf_ex(araresim,font,353,345,makecol(255,255,255),-1,"Hiz:%.0f",a.hiz);
		textprintf_ex(araresim,font,353,357,makecol(255,255,255),-1,"%.1f/%.1f",a.gkm,a.km);
		
		rotate_sprite(araresim,ibre,64,278,itofix(a.devirDegeri()));						//Devir kadraný ayarlamasý.
		
		rotate_sprite(araresim,ibre2,504,276,itofix(a.hizDegeri()));				//Hiz kadraný ayarlamasý.
			
		rotate_sprite(araresim,ibre3,309,163,itofix(a.hararetDegeri()));				//Su kadraný ayarlamasý
		
		rotate_sprite(araresim,ibre4,418,161,itofix(a.yakitDegeri()));				//Yakit kadraný ayarlamasý
					
		
		if(key[KEY_W])
		{
				a.hizlan();	
		}
		
		else if(!key[KEY_W] || a.yakitDegeri()<=32)
		{
			
			if(a.hizSabitleyici==0)
			  	a.fren();
			else if(a.yakitDegeri()<=32 || a.hararetDegeri()>=95)
				a.hizSabitleyici=0;	  			
			
		}
		
		if(key[KEY_S])
		{
			if(a.hizSabitleyici==0)
					a.fren();
			else
				a.hizSabitleyici=0;			
		}
		
		if(key[KEY_SPACE] )
		{
			a.parkFren();
		}
		
		if(key[KEY_H] )
		{
			if(!a.hizSabitleyici)
				a.hizSabitleyici=1;
			else
				a.hizSabitleyici=0;	
		}
		
		if(a.hizSabitleyici)
			
		{
				blit(hizSabitleyici,araresim,0,0,420,265,30,26);
				a.hizSabitleyiciSS();
		}
		
		if(a.yakitDegeri()<=35)
		{
			blit(yakit,araresim,0,0,354,231,24,24);	
		}
		
		if(a.parkFreni)
		{
			if(a.hizSabitleyici==1)
				a.hizSabitleyici=0;
			blit(el_freni,araresim,0,0,354,265,30,25);
		}
		
		if(a.km>=150)
		{
			if(!a.yagBasinciDegeri())
				a.yagBasinciSS();
			blit(yag_basinci,araresim,0,0,420,236,34,16);
		}
		
		if(key[KEY_G] )
		{
			a.kilitlerSS();	
		}
		
		if(a.kilitlerDegeri())
			blit(kilitler,araresim,0,0,422,304,33,20);
		
		if(key[KEY_K])
		{
			a.kemerSS();	
		}
		
		if(a.kemerDegeri())
			blit(kemer,araresim,0,0,354,299,25,28);
		
		
		if(key[KEY_C])
		{
			a.camRezistansiSS();
		}
		
		if(a.camRezistansiDegeri())
			blit(camRezistansi,araresim,0,0,388,231,25,19);
			
		if(a.hararetDegeri()>=90)
			blit(hararet,araresim,0,0,388,265,30,26);
		
		if(key[KEY_E])
		{
			a.kisaFarSS();
		}
		
		if(a.kisaFarDegeri())
			blit(kisaFar,araresim,0,0,763,300,31,25);
		
		if(key[KEY_U])
		{
			a.uzunFarSS();
		}
		
		if(a.uzunFarDegeri())
			blit(uzunFar,araresim,0,0,763,270,33,25);
			
		if(key[KEY_P])
		{
			a.parkLambalariSS();
		}
		
		if(a.parkLambalariDegeri())
			blit(parkLambalari,araresim,0,0,755,330,30,29);	
			
		if(key[KEY_O])
		{
			a.onSisFarSS();
		}
		
		if(a.onSisFarDegeri())
			blit(onSisFar,araresim,0,0,10,299,27,20);		
		
		if(key[KEY_X])
		{
			a.arkaSisLambalariSS();
		}
		
		if(a.arkaSisLambalariDegeri())
			blit(arkaSisLambalari,araresim,0,0,10,330,30,22);
			
		if(key[KEY_D])
		{
			a.sagSinyalSS();
		}
		
		if(a.sagSinyalDegeri() && timer%2==0 )
			blit(sagSinyal,araresim,0,0,505,126,36,29);	
		
		if(key[KEY_A])
		{
			a.solSinyalSS();
		}
		
		if(a.solSinyalDegeri() && timer%2==1 )
			blit(solSinyal,araresim,0,0,265,127,34,29);
			
		if(key[KEY_F])
		{
			a.dortluSinyalSS();
		}
		
		if(a.dortluSinyalDegeri() && timer%2==0 )
		{
			blit(dortluSinyal,araresim,0,0,388,299,30,29);
			blit(solSinyal,araresim,0,0,265,127,34,29);
			blit(sagSinyal,araresim,0,0,505,126,36,29);
		}	
		
		if(mouse_x>=473 && mouse_x<=489 && mouse_y>=347 && mouse_y<=362)
		{
			if(mouse_b & 1)
			{
				a.kmSifirla();
			}
		}
				
		blit(araresim,oyunresim,0,0,0,0,800,500);
		blit(oyunresim,screen,0,0,0,0,800,500);
		rest(60);
		clear_bitmap(oyunresim);
		
	}
	
	Bitir();
	return 0;
}
END_OF_MAIN()




