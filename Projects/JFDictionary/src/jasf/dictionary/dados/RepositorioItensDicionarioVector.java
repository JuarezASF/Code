package jasf.dictionary.dados;

import jasf.dictionary.itemDicionario.ItemDicionario;
import java.util.Vector;

public class RepositorioItensDicionarioVector implements java.io.Serializable{
	Vector<ItemDicionario> itens;
	
	public Vector<ItemDicionario> getItens() {
		return itens;
	}

	public void setItens(Vector<ItemDicionario> itens) {
		this.itens = itens;
	}
	
	public RepositorioItensDicionarioVector(){
		itens = new Vector<ItemDicionario>();
	}
	
	/**
	 * retorna tamanho do vetor de itens
	 * @return
	 */
	public int getSize(){
		return itens.size();
	}
	
	/**
	 * insere item ao final do vetor de intens
	 * @param item
	 */
	public void inserir(ItemDicionario item){
		itens.add(item);
	}
	
	/**
	 * retorna item com nome igual a palavra de entrada.
	 * @param palavra
	 * @return
	 * @throws Exception
	 */
	public ItemDicionario procurar(String palavra)
		throws Exception{
		ItemDicionario resultado = null;
		
		for(int i = 0; i < itens.size(); i++)
			if(this.itens.get(i).getNome().equals(palavra))
				resultado = this.itens.get(i);
		
		if(resultado == null)
			throw new Exception("Item não encontrado!");
		return resultado;
	}
	
	/**
	 * Retorna verdadeiro caso exista um item com nome igual a palavra de entrada.
	 * @param palavra
	 * @return
	 */
	public boolean existe(String palavra){
		boolean resultado = false;
		
		for(int i = 0; i < itens.size(); i++)
			if(this.itens.get(i).getNome().equals(palavra))
				resultado = true;
		
		return resultado;
	}
	
	/**
	 * Atualiza item com o mesmo nome que o item passado.
	 * @param item
	 * @throws Exception
	 */
	public void atualizar(ItemDicionario item)
		throws Exception{
		String nome = item.getNome();
		if(this.existe(nome) == false)
			throw new Exception("O item não pode ser atualizado porque não foi encontrado uma versão anterior deste. Primeiro crie o item, depois atualize-o.");
		for(int i = 0; i < itens.size(); i++)
			if(this.itens.get(i).getNome().equals(nome)){
				itens.set(i, item);
				break;
			}
	}
	
	/**
	 * Remove item com mesmo nome que o item passado.
	 * @param item
	 * @throws Exception
	 */
	public void remover(ItemDicionario item)
	throws Exception{
		String nome = item.getNome();
		if(this.existe(nome) == false)
			throw new Exception("O item não pode ser removido porque não foi encontrado.");
		for(int i = 0; i < itens.size(); i++)
			if(this.itens.get(i).getNome().equals(nome)){
				itens.remove(i);
				break;
			}
	}
	
	/**
	 * Retorna o (n-1)ésimo item
	 * @param n
	 * @return
	 */
	public ItemDicionario getItem(int n){
		return itens.get(n);
	}
	
	public void organiza(){
		quickSort(0, getSize()-1);
	}
	
	/**
	 * Algoritmo retirado da wikipedia. Construído baseado no pseudocódigo em:
	 * http://pt.wikipedia.org/wiki/Quicksort
	 * @param ini
	 * @param fim
	 */
	private void quickSort(int ini, int fim){
		int i,j;
		ItemDicionario pivo, aux;
		String nomePivo, nomeAtual;
		
		i = ini;
		j = fim;
		pivo = this.itens.get((ini + fim)/2);
		nomePivo = pivo.getNome();
		while(i < j){
			nomeAtual = itens.get(i).getNome();
			while(nomeAtual.compareTo(nomePivo) < 0){
				i++;
				nomeAtual = itens.get(i).getNome();
			}
			
			nomeAtual = itens.get(j).getNome();
			while(nomeAtual.compareTo(nomePivo) > 0){
				j--;
				nomeAtual = itens.get(j).getNome();
			}
			
			if(i<=j){
				aux = itens.get(i);
				itens.set(i, itens.get(j));
				itens.set(j, aux);
				i++;
				j--;
			}
		}//fim enquanto
		
		if(j>ini)
			quickSort(ini, j);
		if(i<fim)
			quickSort(i, fim);
	}
	
	}
