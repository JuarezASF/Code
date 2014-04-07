

import java.awt.Color;
import java.awt.Font; 
import java.awt.Graphics;
import java.awt.Image;

/**
 * @author A.A.
 * @version 1.5 [21/07/97]
 *
 */

class Botao
{
  int x0, y0, larg, alt;
  Color cor;
  String nome;
  int offx, offy;
  boolean apagavel, habilitado=true;
  int fonteSIZE=10;

  Botao(int x, int y, int l, int a, Color k, String s)
  { this.cor=k;
    this.x0=x;
    this.y0=y;
    this.larg=l;
    this.alt=a;
    this.nome=s;
    this.offx=0;
    this.offy=0;
    this.apagavel=true;
  }


  Botao(int x, int y, int l, int a, Color k, String s, int ox, int oy)
  { this.cor=k;
    this.x0=x;
    this.y0=y;
    this.larg=l;
    this.alt=a;
    this.nome=s;
    this.offx=ox;
    this.offy=oy;
    this.apagavel=true;
  }

  Botao(int x, int y, int l, int a, Color k, String s, int ox, int oy, int tfonte)
  { this.cor=k;
    this.x0=x;
    this.y0=y;
    this.larg=l;
    this.alt=a;
    this.nome=s;
    this.offx=ox;
    this.offy=oy;
    this.fonteSIZE=tfonte;
    this.apagavel=true;
  }

 Botao(int x, int y, int l, int a, Color k, String s, int ox, int oy, boolean apag)
  { this.cor=k;
    this.x0=x;
    this.y0=y;
    this.larg=l;
    this.alt=a;
    this.nome=s;
    this.offx=ox;
    this.offy=oy;
    this.apagavel=apag;
  }

  public void desabilita()
  { this.habilitado=false;
  }

  public void habilita()
  { this.habilitado=true;
  }

  public void pintaRetangulo(Graphics g)
  { g.setColor(cor);
    g.fill3DRect(x0, y0, larg, alt, true);
  }

  public void pintaBotao(Graphics g)
  { g.setColor(cor);
    g.setFont(new Font("Helvetica", Font.PLAIN, this.fonteSIZE));
    g.fill3DRect(x0, y0, larg, alt, true);
    g.setColor(Cores.corLetra1);
    g.drawString(nome, x0+10+offx, y0+(int)(alt*1.3/2)+offy);
  }

  public void pintaBotao(Graphics g, String nomealt, int offxalt, int offyalt)
  { g.setColor(cor);
    g.setFont(new Font("Helvetica", Font.PLAIN, this.fonteSIZE));
    g.fill3DRect(x0, y0, larg, alt, true);
    g.setColor(Cores.corLetra1);
    g.drawString(nomealt, x0+10+offxalt, y0+(int)(alt*1.3/2)+offyalt);
  }


  public void pintaBotao(Graphics g, int tfonte, String nomealt, int xn, int yn, boolean sem)
  { g.setColor(cor);
    g.setFont(new Font("Helvetica", Font.PLAIN, tfonte));
    g.fill3DRect(x0, y0, larg, alt, true);
    g.setColor(Cores.corLetra1);
    if (sem) g.drawString(nomealt, xn, yn);
       else  g.drawString(nomealt, x0+10+xn, y0+(int)(alt*1.3/2)+yn);
  }



  public void pintaBotao(Graphics g, int tfonte, String nomealt, int offxalt, int offyalt)
  { g.setColor(cor);
    g.setFont(new Font("Helvetica", Font.PLAIN, tfonte));
    g.fill3DRect(x0, y0, larg, alt, true);
    g.setColor(Cores.corLetra1);
    g.drawString(nomealt, x0+10+offxalt, y0+(int)(alt*1.3/2)+offyalt);
  }



  public void apertaBotao(Graphics g)
  { g.setColor(cor);
    g.setFont(new Font("Helvetica", Font.PLAIN, this.fonteSIZE));
    g.fill3DRect(x0, y0, larg, alt, false);
    g.setColor(Cores.corLetra1);
    g.drawString(nome, x0+10+offx, y0+(int)(alt*1.3/2)+offy);
  }

  public void acendeBotao(Graphics g)
  { g.setColor(cor);
    g.setFont(new Font("Helvetica", Font.PLAIN, this.fonteSIZE));
    g.fill3DRect(x0, y0, larg, alt, true);
    g.setColor(Cores.k000ss);
    g.drawString(nome, x0+10+offx, y0+(int)(alt*1.3/2)+offy);
  }

  public void acendeBotao2(Graphics g)
  { g.setColor(cor);
    g.setFont(new Font("Helvetica", Font.PLAIN, this.fonteSIZE));
    g.fill3DRect(x0, y0, larg, alt, true);
    g.setColor(Cores.k000ss);
    g.drawString(nome, offx, offy);
  }

  public void apagaBotao(Graphics g)

  { if (apagavel)
        { g.setColor(cor);
          g.setFont(new Font("Helvetica", Font.PLAIN, this.fonteSIZE));
          g.fill3DRect(x0, y0, larg, alt, true);
          g.setColor(Cores.corLetra1);
          g.drawString(nome, x0+10+offx, y0+(int)(alt*1.3/2)+offy);
        }
  }

  public void estampaImagem(Graphics g, Image img, int x, int y)
  { g.drawImage(img, x, y, null);
  }

  public boolean dentroRetangulo(int x, int y)
  {if (x>=x0 && x<=x0+larg && y>=y0 && y>=y0+alt)
      return true;
      else return false;
  }

}    //fim da classe Botao








