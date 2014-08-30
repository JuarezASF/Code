package jasf.dictionary.itemDicionario;

import sun.org.mozilla.javascript.internal.EcmaError;

public class CadastroItens implements java.io.Serializable{
	
	private RepositorioItensDicionarioVector palavras;
	
	public CadastroItens(){
		palavras = new RepositorioItensDicionarioVector();
	}
	
	public void cadastrar(ItemDicionario item)
	throws Exception{
		if(palavras.existe(item.getNome()))
			throw new Exception("O Item já existe! Se quiser, adicione uma definição ao mesmo!");
		palavras.inserir(item);
	}
	
	public ItemDicionario procurar(ItemDicionario item)
	throws Exception{
		return palavras.procurar(item.getNome());
	}
	
	public boolean existe(ItemDicionario item){
		return palavras.existe(item.getNome());
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
	
	public ItemDicionario[] getItensArray(){
		ItemDicionario[] array = new ItemDicionario[palavras.getSize()];
		try{
		for(int i = 0; i < palavras.getSize(); i++)
			array[i] = palavras.getItem(i);
		}
		catch(Exception E){}
		
		return array;
	}
	

}
