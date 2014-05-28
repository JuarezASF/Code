#Comipilando e Rodando "Ola Mundo" com Icarus Verilog
## Duas formas de compilar:


##### Listando arquivos no comando

compile com:
       
         iverilog -o my_design  counter_tb.v counter.v
         
##### Listando arquivos em 'file_list.txt'
 Cria um arquivo chamado "file_list.txt" com o seguinte conteúdo      

  >counter.v
  
  >counter_tb.v
   
   compile com:
       
        iverilog -o my_design -c file_list.txt  


##Para rodar

Para as duas formas de compilar, o comando é o mesmo:   

        vvp my_design