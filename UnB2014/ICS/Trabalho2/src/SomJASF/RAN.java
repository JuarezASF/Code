package SomJASF;

import java.util.ArrayList;

import javax.swing.JFrame;

import sintese.*;

import org.math.plot.*;
import org.math.plot.utils.Array;

public class RAN extends Envoltoria{
	
	private float a, f_ran;
	private int tamanho_curva;
	private boolean set;
	private int nPontos;
	

	//----------------------------------
	//--------Getters and setters-------
	//----------------------------------
	public int getTamanho_curva() {
		return tamanho_curva;
	}

	/**
	 * Seta novo tamanho da curva e gera nova envoltoria aleatória
	 * @param tamanho_curva
	 */
	public void setTamanho_curva(int new_tamanho_curva) {
		this.tamanho_curva = new_tamanho_curva;
		generateEnvoltoria();
	}
	
	public float getA() {
		return a;
	}

	/**
	 * seta o ganho para a
	 * @param a
	 */
	public void setA(float new_a) {
		this.a = new_a;
		setGanho(a);
	}

	public float getF_ran() {
		return f_ran;
	}

	/**
	 * seta nova frequência de pontos de quebra e gera nova envoltória aleatória
	 * @param f_ran
	 */
	public void setF_ran(float new_f_ran) {
		this.f_ran = new_f_ran;
		generateEnvoltoria();
	}
	//----------------------------------
	//--------Construtores--------------
	//----------------------------------
	/**
	 * Cria Envoltória aleatório entre +1 e -1 com frequência de pontos de quebra
	 * de 60Hz. O tamanho da curva é setado para 720
	 */
	public RAN(){
		setParameters(1f, 60f, 720);
	}
	
	public RAN(float new_a, float new_f_ran){
		setParameters(new_a, new_f_ran, 720);
	}
	
	/**
	 * Cria Envoltória aleatório entre +A e -A com frequência de pontos de quebra
	 * determinada por f_ran e tamanho da curva especificado
	 * @param new_a
	 * @param new_f_ran
	 * @param tamanho_curva
	 */	
	public RAN(float new_a, float new_f_ran, int tamanho_curva){
		setParameters(new_a, new_f_ran, tamanho_curva);
	}
	
	/**
	 * seta os 3 parâmetros da classe e regera a Envoltória aleatória
	 * @param new_a
	 * @param new_f_ran
	 * @param tamanho_curva
	 */
	public void setParameters(float new_a, float new_f_ran, int tamanho_curva){
		set = false;
		setA(new_a);
		setF_ran(new_f_ran);
		setTamanho_curva(tamanho_curva);
		set = true;
		generateEnvoltoria();
	}
	
	//----------------------------------
	//--------Métodos-------------------
	//----------------------------------
	/**
	 * Gera um número pseudoaleatório entre -A e +A
	 * @param amplitude
	 * @return
	 */
	private float getRandomNumber(float amplitude){
		float random = 2f*amplitude*((float)Math.random()) - amplitude;
		
		return random;
	}
	
	/**
	 * Gera uma nova envoltória com os parâmetros já especificados
	 * Note que a envoltória é gerada entre -1 e + 1,
	 * o ganho é aplicado futuramente
	 */
	public void generateEnvoltoria(){
		if (set == false) return;
		Curva curv = new Curva(getTamanho_curva());
		float amplitude = 1f;
		for(float x = 0; x <= tamanho_curva; x+= tamanho_curva/f_ran){
			curv.addPonto(x, getRandomNumber(amplitude));
		}
		
		nPontos = (int)f_ran + 1;
		
		this.setCURVA(curv);
	}
	
	
	/**
	 * Gera um gráfico da envoltória aleatória de -1 a +1 criada
	 * considera que o tamanho máximo da tabela é 720
	 * Se for usar mais do que isso irá dar pau! orriga se necessário!!
	 */
	public void visualiza(){
		// create your PlotPanel (you can use it as a JPanel)
		  Plot2DPanel plot = new Plot2DPanel();
		 
		  

		  Tabela tab = this.getCURVA();
		  
		  ArrayList<Double> x = new ArrayList<Double>(); 
		  ArrayList<Double> y = new ArrayList<Double>(); 
		  for(int i = 0; i <= f_ran; i++){
			  x.add((double )i*tamanho_curva/f_ran);
			  y.add((double )tab.getValorNoIndice(i)*this.a) ;
		  }
		  
		  // add a line plot to the PlotPanel
		  double[] x_array =new double[x.size()];
		  double[] y_array =new double[y.size()];
		  for (int i = 0; i < x_array.length; i++) {
			  x_array[i] = x.get(i).doubleValue();  // java 1.4 style
			  y_array[i] = y.get(i).doubleValue();  // java 1.4 style
		  }
		  
		  plot.addLinePlot("Rand Data", x_array, y_array);
		 
		  // put the PlotPanel in a JFrame, as a JPanel
		  JFrame frame = new JFrame("a plot panel");
		  frame.setContentPane(plot);
		  frame.setVisible(true);
		  frame.setSize(320, 240);
		  frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	

}
