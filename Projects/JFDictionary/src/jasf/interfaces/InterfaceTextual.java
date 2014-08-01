package jasf.interfaces;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import jasf.dictionary.dados.RepositorioItensDicionarioVector;
import jasf.dictionary.itemDicionario.ItemDicionario;

public class InterfaceTextual {
	static void print(ItemDicionario item){
		System.out.println(item.getNome());
		for(int i = 0; i < item.getNDefinicoes(); i++){
			System.out.println("\t" + item.getDefinicao().get(i));
		}
	}
	
	static void print(RepositorioItensDicionarioVector dicionario){
		for(int i = 0; i < dicionario.getSize(); i++){
			InterfaceTextual.print(dicionario.getItem(i));
			System.out.println("-------------------------");
		}
	}
	
	/**
	 * testa operações básicas de criação e edição
	 */
	static void runDemo1(){
		try{
			ItemDicionario meuItem = new ItemDicionario();
			meuItem.setNome("Juarez");
			meuItem.addDefinicao("Uma cara muito chato");
			meuItem.addDefinicao("Namorado da Isabela");
			
			InterfaceTextual.print(meuItem);
			
			System.out.println("\n\n\nCorrigindo....\n\n\n");
			
			meuItem.editaDefinicao(0, "Um cara muito maneiro");
			InterfaceTextual.print(meuItem);
			
			
			}
			catch(Exception E){
				System.out.println(E.getMessage());
			}
	}
	
	/**
	 * Testa o quick sort implementado
	 */
	static void runDemo2(){
		try{
			ItemDicionario iten1 = new ItemDicionario("Juarez");
			iten1.addDefinicao("Namorado da Isabela");
			
			ItemDicionario iten2 = new ItemDicionario("Isabela");
			iten2.addDefinicao("Namorada do Juarez");
			iten2.addDefinicao("Dona da Wendy");
			
			
			ItemDicionario iten3 = new ItemDicionario("Wendy");
			iten3.addDefinicao("Gata da Isabela");
			iten3.addDefinicao("Não gosta do Juarez");
			
			RepositorioItensDicionarioVector dicionario = new RepositorioItensDicionarioVector();
			dicionario.inserir(iten1);
			dicionario.inserir(iten2);
			dicionario.inserir(iten3);
			
			InterfaceTextual.print(dicionario);
			System.out.println("\n\n\nOrganizando....\n\n\n");
			dicionario.organiza();
			InterfaceTextual.print(dicionario);
			
			}
			catch(Exception E){
				System.out.println(E.getMessage());
			}
	}

	/**
	 * Testa o quick sort implementado
	 */
	static void runDemo3(){
		try{
			ItemDicionario iten1 = new ItemDicionario("Z");
			ItemDicionario iten2 = new ItemDicionario("X");
			ItemDicionario iten3 = new ItemDicionario("C");
			ItemDicionario iten4 = new ItemDicionario("V");
			ItemDicionario iten5 = new ItemDicionario("B");
			ItemDicionario iten6 = new ItemDicionario("N");
			ItemDicionario iten7 = new ItemDicionario("M");
			
			
	
			
			RepositorioItensDicionarioVector dicionario = new RepositorioItensDicionarioVector();
			dicionario.inserir(iten1);
			dicionario.inserir(iten2);
			dicionario.inserir(iten3);
			dicionario.inserir(iten4);
			dicionario.inserir(iten5);
			dicionario.inserir(iten6);
			dicionario.inserir(iten7);
			
			
			InterfaceTextual.print(dicionario);
			System.out.println("\n\n\nOrganizando....\n\n\n");
			dicionario.organiza();
			InterfaceTextual.print(dicionario);
			
			}
			catch(Exception E){
				System.out.println(E.getMessage());
			}
	}
	
	/**
	 * testando serialização da classe repositório
	 */
	static void runDemo4(){
		try{
			ItemDicionario iten1 = new ItemDicionario("Juarez");
			iten1.addDefinicao("Namorado da Isabela");
			
			ItemDicionario iten2 = new ItemDicionario("Isabela");
			iten2.addDefinicao("Namorada do Juarez");
			iten2.addDefinicao("Dona da Wendy");
			
			
			ItemDicionario iten3 = new ItemDicionario("Wendy");
			iten3.addDefinicao("Gata da Isabela");
			iten3.addDefinicao("Não gosta do Juarez");
			
			RepositorioItensDicionarioVector dicionario = new RepositorioItensDicionarioVector();
			dicionario.inserir(iten1);
			dicionario.inserir(iten2);
			dicionario.inserir(iten3);
			
			
			FileOutputStream fileOut =
			         new FileOutputStream("./meusDados.ser");
			         ObjectOutputStream out = new ObjectOutputStream(fileOut);
			         out.writeObject(dicionario);
			         out.close();
			         fileOut.close();
			         System.out.printf("Serialized data is saved in ./meusDados.ser");
			
			}
			catch(IOException i){
	          i.printStackTrace();
			}
			catch(Exception E){
				System.out.println(E.getMessage());
			}
	}
	
	public static void runDemo5()
	   {
	      RepositorioItensDicionarioVector e = null;
	      try
	      {
	         FileInputStream fileIn = new FileInputStream("./meusDados.ser");
	         ObjectInputStream in = new ObjectInputStream(fileIn);
	         e = (RepositorioItensDicionarioVector) in.readObject();
	         in.close();
	         fileIn.close();
	      }catch(IOException i)
	      {
	         i.printStackTrace();
	         return;
	      }catch(ClassNotFoundException c)
	      {
	         System.out.println("RepositorioItensDicionarioVector class not found");
	         c.printStackTrace();
	         return;
	      }
	      System.out.println("Deserialized Object...");
	      InterfaceTextual.print(e);
	   }


	
}
