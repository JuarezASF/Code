import java.awt.Color;
import java.awt.Font;
import java.util.ArrayList;

import javax.swing.JFrame;

import sintese.*;

import org.math.plot.*;
import org.math.plot.plotObjects.BaseLabel;
import org.math.plot.utils.Array;

public class RAN2 extends Dispositivo{
	
	private float incremento, inicio, acumulador, indice;
	private Tabela randomTable;
	private int tamanhoTabela;
	private Dispositivo A, F;


	public RAN2(){

	}

	void inicializa(Dispositivo amplitude, Dispositivo frequencia, float fase, int tamanhoTabela, float frequenciaAmostragem){
		this.tamanhoTabela = tamanhoTabela;
		inicio = fase/360.0 * tamanhoTabela;
		incremento = 
	}
	

	/**
	 * Gera Envoltória aleatória com f_ran potnos espaçados de 720/f_ran 
	 * @param new_f_ran número de pontos de quebra na envoltoria aleatória
	 */
	private void generateRandomEnv(float new_f_ran){
		Curva curv = new Curva(720);
		float amplitude = 1f;
		float passo = 720f/new_f_ran;
		for(float x = 0; x <= 720; x+= passo){
			float myRand = getRandomNumber(amplitude);
			curv.addPonto(x, myRand);
		}
		
		this.randomEnv = new Envoltoria();
		this.randomEnv.setCURVA(curv);
	}
	/**
	 * Gera um número pseudoaleatório entre -A e +A
	 * @param amplitude
	 * @return
	 */
	private float getRandomNumber(float amplitude){
		float random = 2f*amplitude*((float)Math.random()) - amplitude;
		
		return random;
	}
		
	
	
}
