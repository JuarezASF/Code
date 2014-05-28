#Comipilando e Rodando "Ola Mundo" com Icarus Verilog

1. Instale o Icarus Verilog pelo synaptic
2. crie o arquivo hello.v contendo o seguinte código;

        
          module main;
              initial 
                begin
                  $display("Hello, World");
                  $finish ;
                end
            endmodule
            
3. compile com:

        iverilog -o hello hello.v
        
4. rode com 

        vvp hello
        
from [tutorial](http://iverilog.wikia.com/wiki/Getting_Started):
>The "iverilog" and "vvp" commands are the most important commands available to users of Icarus Verilog. The "iverilog" command is the compiler, and the "vvp" command is the simulation runtime engine. What sort of output the compiler actually creates is controlled by command line switches, but normally it produces output in the default vvp format, which is in turn executed by the vvp program. 


