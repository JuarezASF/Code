package jasf.dictionary;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import jasf.dictionary.itemDicionario.CadastroItens;
import jasf.dictionary.itemDicionario.ItemDicionario;
import jasf.dictionary.itemDicionario.RepositorioItensDicionarioVector;

/**
 * Centraliza as a��es do dicion�rio e ofere m�todos para salvar e carregar dados.
 * Para carregar um dicion�rio anterior, utilize o m�todo void abrir(String fileName).
 * @author JuarezASF
 *
 */
public class Fachada {
	
	private CadastroItens palavras;
	
	public Fachada(){
		palavras = new CadastroItens();
	}

	public Fachada(String fileName)
	throws Exception{
			abrir(fileName);
	}
	
	public void cadastrar(ItemDicionario item)
	throws Exception{
		palavras.cadastrar(item);
	}
	
	public ItemDicionario procurar(ItemDicionario item)
	throws Exception{
		return palavras.procurar(item);
	}
	
	public boolean existe(ItemDicionario item){
		return palavras.existe(item);
	}
	
	public void atualizar(ItemDicionario item)
	throws Exception{
		palavras.atualizar(item);
	}
	
	public void remover(ItemDicionario item)
	throws Exception{
		palavras.remover(item);
	}
	
	public void organiza(){
		palavras.organiza();
	}
	
	public ItemDicionario getItem(int n)
	throws Exception{
		return palavras.getItem(n);
	}
	
	public ItemDicionario[] getArrayPalavras(){
		return palavras.getItensArray();
	}
	
	public void salvar(String fileName)
	throws IOException{

			FileOutputStream fileOut =
			         new FileOutputStream(fileName);
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			out.writeObject(palavras);//primeiro escrevemos as palavras
			out.close();
			fileOut.close();
			System.out.printf("Serialized data is saved in " + fileName);	
	}
	
	public void abrir(String fileName)
	throws Exception{
	      try
	      {
	         FileInputStream fileIn = new FileInputStream("./meusDados.ser");
	         ObjectInputStream in = new ObjectInputStream(fileIn);
	         palavras = (CadastroItens) in.readObject();
	         in.close();
	         fileIn.close();
	      }catch(IOException i)
	      {
	    	  throw new Exception("Arquivo n�o pode ser aberto!");
	      }catch(ClassNotFoundException c)
	      {
	    	  throw new Exception("Alguma(s) das classe n�o pode ser acessada! Verifique compatibildade dos dados salvos e lidos!!");
	      }

	}

}
