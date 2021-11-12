-- Testbench created online at:
--   https://www.doulos.com/knowhow/perl/vhdl-testbench-creation-using-perl/
-- Author: Mücahit KURTLAR License: MIT
--<Begin license text.>
--Copyright 2021 Mücahit KURTLAR

--Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

--The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

--THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
--<End license text.>

library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity your_name_and_id_here is
end;

architecture bench of your_name_and_id_here is

  component your_name_and_id_here
      Port ( X : in STD_LOGIC;
             Y : in STD_LOGIC;
             Z : in STD_LOGIC;
             F : out STD_LOGIC);
  end component;

  signal X: STD_LOGIC;
  signal Y: STD_LOGIC;
  signal Z: STD_LOGIC;
  signal F: STD_LOGIC;

begin

  uut: your_name_and_id_here port map ( X => X,
                                               Y => Y,
                                               Z => Z,
                                               F => F );

  stimulus: process
  begin
  
    -- Put initialisation code here
    X <= '0';
    Y <= '0';
    Z <= '0';
    wait for 10 ns;
    X <= '0';
    Y <= '0';
    Z <= '1';
    wait for 10 ns;
    X <= '0';
    Y <= '1';
    Z <= '0';
    wait for 10 ns;
    X <= '0';
    Y <= '1';
    Z <= '1';
    wait for 10 ns;
    X <= '1';
    Y <= '0';
    Z <= '0';
    wait for 10 ns;
    X <= '1';
    Y <= '0';
    Z <= '1';
    wait for 10 ns;
    X <= '1';
    Y <= '1';
    Z <= '0';
    wait for 10 ns;
    X <= '1';
    Y <= '1';
    Z <= '1';
    wait for 10 ns;
    

    -- Put test bench stimulus code here

  end process;


end;
