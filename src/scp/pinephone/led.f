\ PIO config and data registers pin bank D
: pdcfg  1c20874 ;
: pddata 1c2087c ;

\ configure led pins as outputs
1 pdcfg 8 3 bf!  1 pdcfg c 3 bf!  1 pdcfg 10 3 bf!

\ ( bool -- ) enable/disable led
: green  pddata 12 b! ;
: red    pddata 13 b! ;
: blue   pddata 14 b! ;

\ enable green led during boot
1 green
