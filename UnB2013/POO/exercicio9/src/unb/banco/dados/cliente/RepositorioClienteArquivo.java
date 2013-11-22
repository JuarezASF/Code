package unb.banco.dados.cliente;

import unb.banco.cliente.Cliente;
import unb.banco.cliente.ClienteJaCadastrado;
import unb.banco.cliente.ClienteNaoCadastradoException;
import unb.banco.cliente.listaClientes;

import java.io.*;

public class RepositorioClienteArquivo implements RepositorioCliente{
		private String fileData;
		private String auxFile;
		private int size;

		public RepositorioClienteArquivo()
		throws Exception
		{
			setSize(0);
			String tempDir = System.getProperty("user.dir") + File.separator;
			fileData = tempDir + "clientesData.txt";
			auxFile = tempDir + "clientesDataAux.txt";
			
			File f = new File (fileData);
			File f2 = new File (auxFile);
			
			try {
				f.createNewFile();
				f2.createNewFile();
			} catch (IOException e) {
				throw new Exception("Falha ao criar arquivo de clientes!");
			}			
			updateIndice();
		}


		private void updateIndice()
		throws Exception
		{			
			setSize(numberOfClientes());
		}
	

	public String getFileData() {
			return fileData;
		}


		public void setFileData(String fileData) {
			this.fileData = fileData;
		}


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
		
	private int numberOfClientes()
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
	         //le primeiro cpf
	         while(line != null) 
	         {      
	                 br.readLine();
	                 //lê nome
	                 line = br.readLine();
	                 //pula linha em branco
	                 line = br.readLine();
	                 //lê o próximo cpf
	                 i++;
	         }
         }
         catch(Exception e){
        	 throw new Exception("Falha ao manipular arquivo!");
         }
         finally{
         br.close();
         ir.close();
         }
         return i;
	}

	public Cliente[] getClientes()
		throws Exception
	{
        FileReader ir = null;
        BufferedReader br = null;
		
         Cliente[] clientes = new Cliente[getSize()];
         int i = 0;
        
         try{
	        ir = new FileReader(getFileData());
	 		br = new BufferedReader(ir);
	         
	         String line = br.readLine();
	         line = br.readLine();
	         while(line != null) 
	         {                                
	                 String cpf = line;
	                 String name = br.readLine();
	
	                 Cliente current = new Cliente(name, cpf);
	                 clientes[i++] = current;
	                 
	                 line = br.readLine();
	                 //pula linha em branco
	                 line = br.readLine();
	                 //lê o próximo cpf
	         }
         }
         catch(Exception e){
        	 throw new Exception("Falha ao manipular arquivo!");
         }
         finally{
         br.close();
         ir.close();
         }
         return clientes;
	}
	
	public Cliente getCliente(int n)
		throws Exception
	{
		Cliente[] clientes = getClientes();
		return clientes[n];
	}
	
	public void setClientes(Cliente[] newCl)
		throws Exception
	{
	}

	public void setClientes(listaClientes lista)
			throws Exception
		{
		}
	
	public void escreverCliente(Cliente target) 
			throws IOException
		{
			boolean append = true;
	        FileWriter fout = new FileWriter(fileData, append);
	        BufferedWriter bw = new BufferedWriter(fout);
	                
	        bw.newLine();
	        bw.write(target.getCpf());
	        bw.newLine();
	        bw.write(target.getName());
	        bw.newLine();
	                        
	        bw.close();
	        fout.close();
		}

	
	public void inserir(Cliente target) 
			throws ClienteJaCadastrado, 
			Exception
	{
		if(target == null)
			throw new Exception("repositórioCliente recebeu cliente nulo!");
		try{
			escreverCliente(target);
			setSize(getSize()+1);
			}
		catch(IOException e)
			{
			throw new Exception("Erro ao escrever em arquivo!");
			}
	}
	
	
	public boolean existe(Cliente target)
			throws Exception
	{
        FileReader ir = null;
        BufferedReader br = null;
        
        ir = new FileReader(getFileData());
 		br = new BufferedReader(ir);
        
         boolean result = false;
         
         String line = br.readLine();
         line = br.readLine();
         while(line != null) 
         {                                
                 String cpf = line;
                 if(cpf.equals(target.getCpf()))
                	 {
                	 result = true;
                	 break;
                	 }
                 br.readLine();
                 //pula linha do nome
                 line = br.readLine();
                 //pula linha em branco
                 line = br.readLine();
                 //lê o próximo cpf
         }
         
         br.close();
         ir.close();
         
         return result;
	}
	public Cliente procurar(Cliente target) 
			throws Exception
	{
        FileReader ir = null;
        BufferedReader br = null;
        
        ir = new FileReader(getFileData());
 		br = new BufferedReader(ir);
         Cliente found = null;
         
         String line = br.readLine();
         line = br.readLine();
         while(line != null) 
         {                                
                 String cpf = line;
                 String name = br.readLine();
                 if(cpf.equals(target.getCpf()))
                	 {
                	 found = new Cliente(name, cpf);
                	 break;
                	 }
                 line = br.readLine();
                 //pula linha em branco
                 line = br.readLine();
                 //lê o próximo cpf
         }
         
         br.close();
         ir.close();
         
         if(found == null)
        	 throw new ClienteNaoCadastradoException();
         
         return found;

	}
	
	public void atualizar(Cliente target)
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
         line = br.readLine();
         while(line != null) 
         {                                
              String cpf = line;
              String name = br.readLine();
              if(cpf.equals(target.getCpf()))
              {
            	  name = target.getName();
            	  success = true;
              }
              bw.newLine();
		      bw.write(cpf);
	          bw.newLine(); 
	          bw.write(name);
	     	  bw.newLine();

                 
              line = br.readLine();
                 //pula linha em branco
              line = br.readLine();
                 //lê o próximo cpf
         }
         
         br.close();
         ir.close();

         bw.close();
         fout.close();

         File fileDataFile = new File(getFileData());
         
         fileDataFile.delete();
         auxFileFile.renameTo(fileDataFile);
         
         if(success == false)
        	 throw new ClienteNaoCadastradoException();

	}
	
	public void remover(Cliente target)
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
         line = br.readLine();
         while(line != null) 
         {                                
                 String cpf = line;
                 String name = br.readLine();
                 if(!cpf.equals(target.getCpf()))
                 {
             	    bw.newLine();
        	        bw.write(cpf);
        	        bw.newLine();
        	        bw.write(name);
        	        bw.newLine();
                 }
                 else
                 {
                	 success = true;
                	 setSize(getSize() - 1);
                 }
                 line = br.readLine();
                 //pula linha em branco
                 line = br.readLine();
                 //lê o próximo cpf
         }
         
         br.close();
         ir.close();

         bw.close();
         fout.close();

         File fileDataFile = new File(getFileData());
         
         fileDataFile.delete();
         auxFileFile.renameTo(fileDataFile);
         
         if(success == false)
        	 throw new ClienteNaoCadastradoException();
		
	}
}
