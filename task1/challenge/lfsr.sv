module lfsr (                 //linear feedback shift register
    input logic rst,
    input logic en,
    input logic clk,
    output logic [6:0]data_out
);
    
    logic [6:0] sreg; //shift register
    
    always_ff @(posedge clk) begin
        if(rst) begin
            sreg <= 7'b1;
        end 
        
        else if (en) begin
            sreg[6] <= sreg[5];
            sreg[5] <= sreg[4];
            sreg[4] <= sreg[3];
            sreg[3] <= sreg[2];
            sreg[2] <= sreg[1];
            sreg[1] <= sreg[0];
            sreg[0] <= sreg[6] ^ sreg[2]; //xor
        end

    end

    assign data_out = sreg;

endmodule