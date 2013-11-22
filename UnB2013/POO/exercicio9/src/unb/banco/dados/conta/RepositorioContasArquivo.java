package unb.banco.dados.conta;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import unb.banco.cliente.Cliente;
import unb.banco.conta.ClasseContaInvalidaException;
import unb.banco.conta.Conta;
import unb.banco.conta.ContaBonificada;
import unb.banco.conta.Poupanca;
import unb.userIterface.UserInterface;


public class RepositorioContasArquivo implements RepositorioConta{

	private String fileData, auxFile;
	private int size;

	public String getAuxFile() {
		return auxFile;
	}

	public void setAuxFile(String auxFile) {
		this.auxFile = auxFile;
	}
	public int getSize() {
		return size;
	}
	public void setSize(int size) {
		this.size = size;
	}
	public RepositorioContasArquivo()
		throws Exception
	{
		setSize(0);
		String tempDir = System.getProperty("user.dir") + File.separator;
		fileData = tempDir + "contasData.txt";
		auxFile = tempDir + "contasDataAux.txt";
		
		File f = new File (fileData);
		File f2 = new File (auxFile);
		
		try {
			f.createNewFile();
			f2.createNewFile();
		} catch (IOException e) {
			throw new Exception("Falha ao criar arquivo de contas!");
		}			
		updateIndice();
	}

	public int getIndice() {
		return size;
	}

	public String getFileData() {
		return fileData;
	}

	public void setFileData(String fileData) {
		this.fileData = fileData;
	}

	
	public Conta[] getContas()
		throws Exception
	{
        FileReader ir = null;
        BufferedReader br = null;
		
         Conta[] contas = new Conta[getSize()];
         int i = 0;
        
         try{
	        ir = new FileReader(getFileData());
	 		br = new BufferedReader(ir);
	         
	 		String line = br.readLine();
	 		//le a linha em branco
	 		line = br.readLine();
			//le primeiro tipo

	         while(line != null) 
	         {                                
	                 String tipo = line;
	                 Conta current = readConta(br, tipo);
	
	                 contas[i++] = current;
	                 
	          		 line = br.readLine();
	         		//le a linha em branco
	         		line = br.readLine();
	        		//le primeiro tipo
	         }
         }
         catch(Exception e){
        	 throw new Exception("Falha ao manipular arquivo!");
         }
         finally{
         br.close();
         ir.close();
         }
         return contas;

	}

	
	public Conta getConta(int n) 
		throws Exception
	{
		Conta[] contas = getContas();
		
		if(n < contas.length && n >= 0)
			return contas[n];
		else
			throw new Exception("Indice inválido em getConta(int n)!");
	}

	private int numberOfcontas()
			throws Exception
		{
	        FileReader ir = null;
	        BufferedReader br = null;
			
	         int i = 0;
	        
	         try{
		        ir = new FileReader(getFileData());
		 		br = new BufferedReader(ir);
		         
		         String line = br.readLine();
		         //le primeira linha em branco
		         line = br.readLine();
		         //le primeiro tipo
		         while(line != null) 
		         {      
		        	 String tipo = line;
		        	 readConta(br, tipo);
		  
		        	 line = br.readLine();
		             //pula linha em branco
		             line = br.readLine();
		             //lê o próximo cpf
		              i++;
		         }
	         }
	         catch(Exception e){
	        	 throw new Exception("Falha ao manipular arquivo em numberOfCOntas!");
	         }
	         finally{
	         br.close();
	         ir.close();
	         UserInterface.report("achei " + i + " contas!");
	         }

	         return i;
		}


	private void	updateIndice()
		throws Exception
	{
		setSize(numberOfcontas());

	}
	
	
	public void setContas(Conta[] newC) 
		throws Exception
	{		
		try{
		File fileData = new File(getFileData());
		fileData.delete();
		fileData.createNewFile();
		}
		catch(IOException e){
			throw 
			new Exception("Falha ao deletar ou criar o repositorioClientesArquivo");
		}

		for(int i = 0; i < newC.length; i++)
			if(newC[i] != null)
				inserir(newC[i]);

		updateIndice();
	}
	
	private void writeConta(Conta target, BufferedWriter bw)
		throws ClasseContaInvalidaException,
		Exception
	{
		if(target instanceof Conta)
		{
		try
		{
			bw.write("Conta");
			bw.newLine();
	
			bw.write(target.getNumber());
			bw.newLine();
			
			bw.write(Double.toString(target.getSaldo()));
			bw.newLine();
				
			bw.write(target.getDono().getCpf());
			bw.newLine();
		}
		catch(IOException e)
			{
			throw new Exception("falha ao escrever em arquivo em writeConta!");
			}
		}
		else
			throw new Exception(
					"Tipo errado de conta passado para writeConta" + 	
					"\n should never happen!");
	}

	private void writeContaBonificada(ContaBonificada target, BufferedWriter bw)
			throws ClasseContaInvalidaException,
			Exception
		{
			if(target instanceof ContaBonificada)
			{
			try
			{
				bw.write("ContaBonificada");
				bw.newLine();
		
				bw.write(target.getNumber());
				bw.newLine();;
		
				bw.write(Double.toString(target.getSaldo()));
				bw.newLine();
				
				bw.write(Double.toString(target.getBonus()));
				bw.newLine();
				
				bw.write(target.getDono().getCpf());
				bw.newLine();	
			}
			catch(IOException e)
				{
				throw new Exception("falha ao escrever em arquivo em writeContaBonificada!");
				}
			}
			else
				throw new Exception(
						"Tipo errado de conta passado para writeContaBonificada" + 	
						"\n should never happen!");
		}

	private void writeContaPoupanca(Poupanca target, BufferedWriter bw)
			throws Exception
		{
			if(target instanceof Poupanca)
			{
			try
			{
				bw.write("Poupanca");
				bw.newLine();
		
				bw.write(target.getNumber());
				bw.newLine();
				
				bw.write(Double.toString(target.getSaldo()));
				bw.newLine();						
				
				bw.write(target.getDono().getCpf());
				bw.newLine();
			}
			catch(IOException e)
				{
				throw new Exception("falha ao escrever em arquivo em writePoupanca!");
				}
			}
			else
				throw new Exception(
						"Tipo errado de conta passado para writePoupanca" + 	
						"\n should never happen!");
		}



	public void escreverConta(Conta target) 
			throws Exception, ClasseContaInvalidaException
		{
				
		boolean append = true;
        FileWriter fout = new FileWriter(fileData, append);
        BufferedWriter bw = new BufferedWriter(fout);

		bw.newLine();
		if(target instanceof ContaBonificada)
			writeContaBonificada((ContaBonificada)target, bw);
		else if(target instanceof Poupanca)
			writeContaPoupanca((Poupanca)target, bw);
		else
			writeConta(target, bw);

		bw.close();
		fout.close();
		}
	
	public void escreverConta(Conta target, BufferedWriter bw) 
			throws Exception, ClasseContaInvalidaException
		{				
		bw.newLine();
		if(target instanceof ContaBonificada)
			writeContaBonificada((ContaBonificada)target, bw);
		else if(target instanceof Poupanca)
			writeContaPoupanca((Poupanca)target, bw);
		else
			writeConta(target, bw);

		}
	
	
	public void inserir(Conta target) throws Exception 	
	{
		try{
				if( target != null)
					{
					escreverConta(target);
					setSize(getSize() + 1);
					}
			}
			catch(IOException e){
				throw new Exception("Operação não pode ser concluída!" + 
								"\n Falha ao acessa arquivo!");
			}
	}
	
	private Conta readConta(BufferedReader br, String tipo)
			throws Exception
	{		
		if(tipo.equals("ContaBonificada")){
			String number  = br.readLine();
			double saldo   = Double.valueOf(br.readLine());
			double bonus   = Double.valueOf(br.readLine());
			String cpfDono = br.readLine();
			
			Cliente dono = new Cliente("", cpfDono);
			ContaBonificada target = new ContaBonificada(number, dono, saldo, bonus);
			
			return (Conta) target;
		}
		else if(tipo.equals("Poupanca")){
			String number  = br.readLine();
			double saldo   = Double.valueOf(br.readLine());
			String cpfDono = br.readLine();
			
			Cliente dono = new Cliente("", cpfDono);
			Poupanca target = new Poupanca(number, dono, saldo);
			
			return (Conta) target;
			
		}
		else if(tipo.equals("Conta")){
			String number  = br.readLine();
			double saldo   = Double.valueOf(br.readLine());
			String cpfDono = br.readLine();
			
			Cliente dono = new Cliente("", cpfDono);
			Conta target = new Conta(number, dono, saldo);
			
			
			return target;
		}
		
		else
			throw new ClasseContaInvalidaException(
					"tipo de conta" + tipo + " não identificada em arquivo!" +
			"should never happen");
			
	}
	
	public boolean existe(Conta target) 
		throws Exception
	{
		boolean success = false;
		
        FileReader ir = null;
        BufferedReader br = null;
        
        ir = new FileReader(getFileData());
 		br = new BufferedReader(ir);

 		String line = br.readLine();
 		//le a linha em branco
 		line = br.readLine();
		//le primeiro tipo
 		while(line != null)
		{
 			String tipo = line;
			Conta current = readConta(br, tipo);
			if(current.getNumber().equals(target.getNumber()))
				{
				success = true;
				break;
				}
			line = br.readLine();
			//le a linha em branco
			line = br.readLine();
			//le o tipo
		}
		
        br.close();
        ir.close();
 		
		return success;
	}


	public void atualizar(Conta target) 
			throws Exception {
        FileReader ir = null;
        BufferedReader br = null;
        
        ir = new FileReader(getFileData());
 		br = new BufferedReader(ir);
        
 		File auxFileFile = new File(getAuxFile());
        auxFileFile.delete();
        auxFileFile.createNewFile();
        
		boolean append = true;
	    FileWriter fout = new FileWriter(auxFile, append);
	    BufferedWriter bw = new BufferedWriter(fout);
	     
         boolean success = false;
 
         String line = br.readLine();
         //lê a linha em branco
         line = br.readLine();
         //lê o primeiro tipo
         while(line != null) 
         {                                
   			String tipo = line;
  			Conta current = readConta(br, tipo);
  			if(current.getNumber().equals(target.getNumber()))
  				{
  				success = true;
  				current.setDono(target.getDono());
  				current.setSaldo(target.getSaldo());
  				if(current instanceof ContaBonificada && target instanceof ContaBonificada)
  					((ContaBonificada) current).setBonus(((ContaBonificada) target).getBonus());
  				}
  			escreverConta(current, bw);
  			line = br.readLine();
  			//le a linha em branco
  			line = br.readLine();
  			//le o tipo
         }
         
         br.close();
         ir.close();

         bw.close();
         fout.close();

         File fileDataFile = new File(getFileData());
         
         fileDataFile.delete();
         auxFileFile.renameTo(fileDataFile);
         
         if(success == false)
        	 throw new ContaNaoCadastradaException();
	}


	public Conta procurar(Conta target) 
			throws Exception 
	{	
        FileReader ir = null;
        BufferedReader br = null;
        
        ir = new FileReader(getFileData());
 		br = new BufferedReader(ir);
         Conta found = null;
         
         String line = br.readLine();
         //lê a linha em branco
         line = br.readLine();
         //lê o primeiro tipo
         while(line != null) 
         {                                
       			String tipo = line;
        		Conta current = readConta(br, tipo);
      			if(current.getNumber().equals(target.getNumber()))
       				{
          			found = current;
          			break;
          			}

                line = br.readLine();
                 //lê a linha em branco
                 line = br.readLine();
                 //lê o primeiro tipo
         }
         
         br.close();
         ir.close();
         
         if(found == null)
        	 throw new ContaNaoCadastradaException();
         
         return found;
	}


	public void remover(Conta target) 
			throws Exception
	{
        FileReader ir = null;
        BufferedReader br = null;
        
        ir = new FileReader(getFileData());
 		br = new BufferedReader(ir);
        
 		File auxFileFile = new File(getAuxFile());
        auxFileFile.delete();
        auxFileFile.createNewFile();
        
		boolean append = true;
	    FileWriter fout = new FileWriter(auxFile, append);
	    BufferedWriter bw = new BufferedWriter(fout);
	     
         boolean success = false;
 
         String line = br.readLine();
         //lê a linha em branco
         line = br.readLine();
         //lê o primeiro tipo
         while(line != null) 
         {                                
   			String tipo = line;
  			Conta current = readConta(br, tipo);
  			if(!current.getNumber().equals(target.getNumber()))
  				{
  	  			escreverConta(current, bw);  	
  				}
  			else
	  			{
	  				success = true;
	  				setSize(getSize()-1); 
	  			}
  			line = br.readLine();
  			//le a linha em branco
  			line = br.readLine();
  			//le o tipo
         }
         
         br.close();
         ir.close();

         bw.close();
         fout.close();

         File fileDataFile = new File(getFileData());
         
         fileDataFile.delete();
         auxFileFile.renameTo(fileDataFile);
         
         if(success == false)
        	 throw new ContaNaoCadastradaException();
	}

	
	public Conta procura(Cliente cliente, int n)
			throws Exception {
		return this.procura(cliente.getCpf(), n);
	}

	
	public Conta procura(String targetCPF, int n)
			throws Exception 
	{
        FileReader ir = null;
        BufferedReader br = null;
        
        ir = new FileReader(getFileData());
 		br = new BufferedReader(ir);
         Conta found = null;
         
         String line = br.readLine();
         //lê a linha em branco
         line = br.readLine();
         //lê o primeiro tipo
         while(line != null) 
         {                                
       			String tipo = line;
        		Conta current = readConta(br, tipo);
      			if(current.getDono().equals(targetCPF))
       				{
          			found = current;
          			break;
          			}

                line = br.readLine();
                 //lê a linha em branco
                 line = br.readLine();
                 //lê o primeiro tipo
         }
         
         br.close();
         ir.close();
         
				
		return found;
	}
	

}
