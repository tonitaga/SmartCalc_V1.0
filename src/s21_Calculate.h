#ifndef SRC_S21_CALCULATE_H_
#define SRC_S21_CALCULATE_H_







/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





/*===========================================================*/
/*                                                           */
/*      This file was created to combine other .h files      */
/*                                                           */
/*===========================================================*/





/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%@@@@@@@@@@@@@@@@@@%%%==========%@%%%@%%%=+++*******+%@@@@@@@@@@=+***:
@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%@@%@@@@@@@%%%%====%===%@%%%@%==%%=%####@%@@@@@@@@@@%+******:
@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%=======+++==%%%%%%%%%====@%%%@%====%######@@@@@@@@###+******::
@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%=+++******+****+++==%======%%@%%%%%=====#######@@@##@+*%##@****:::
@@@@@@@@@@@@@@@@@%%%%%%%%%%%=+++*+*****++*++++++++=+=%+++*+***+*+=%%%=====#######@@##+****@##@****::
#@@@@@@@@@@@@@@@@%%%%%%%%+*****+++++++++++++==+=%%===++++++*+*******===%%@#########@+*****=###=***::
##@@@@@@@@@@@@%%%%%%%%%=++=====++++*******+***+==%%=++***********++***+%@@###@####@===*****###%***::
#@@@@@@@@@@@@@@@@%%%=======++*****************+=+=+++**************++=++*%@##%#####====%===###@*****
#@@@@@@@@@@@@@@@%%%%++===+*************++++****==+++++*****************+=++@######%%@#@%%%%%=******+
@@@@@@@@@@@@%@%%%=+++==+*****++++*+===+********+=++*********************++++@##%==++++=+*+=++**++===
@@@@@@@@@@@@@%%%=++==++****+===+====+*********+=+++++******************++++=@#@=++++++++*+++++*****=
@@@@@@@@@@@@%%%++====+*****=%=+===+**********+=%=+++===+***+++***++++++====%%##@=+++*++++=+++==++***
@@@@@@@@@@@%%%++==%=******+@%===+***+++++**+==@%=*=++=+++++***++***++++++++=@@###%=+*++=++++++*+==+*
@@@@@@@@@@@%%++==@=+++****=@===+**++===++*++=%===+==+*++++******+++**++***+=%@#####%=+*+==+**+***+++
@@@@@@@@##@%++=%@+++++****%=+=**+=====*++++%%=====+%%=*+++++++****+==+*++++%%@@@#####@=+++=+*******+
#@@@@@@@###%===%++=+++***+%++*+=====++++++%==%%%%=%+==%+*+====+++***+==++++=%@@@@@%%@###@=+==+******
#####@@@##@====+++=++****=%=+======+=+++++==*==+**++++++=+*+===++++**++%+++*=%@@@@@@@#####%++=++****
@########@===+=+++++++***==========++++++=++*++****++=*++==+*++++++++++++++++=%@@@@@==#####%+=%=+***
@@@@@@@@#%==+=+*===+++***=======%+*+++++++++*++++***+*=+*++==%++++++=****=+++++@%@%@@%=#####%+=%+=+*
@@@@@%%@#==++=++===+=++**====%%%+++++=+=+++*++=+******+*==*++=+=%+++++******===+%@%%@%@=#####%+=%=+=
@@@@@@###=++==++=====+++*%=%%%=++++=%++++++*=+**+**+***=@#@@#######@==**+**:*++*++@=@%@@%#####===%++
@%+%#####++===++=====+++*%%@@=====%+++++*+*+=+**++**=########@+%@#@=%%@@===%==+++**%%%##@@####@===%+
######@##====%+=====+++++%@%%%%==+++=++++++==****%##########%@@%==+====%%@@=***+==+++%@###@####%===%
%@@@%%###%+=%%+=====++++*=@@%%%%====+++*+====****====%#@%@%=+++===+===+++==%%==***+==+=@@##@####====
@@@%=%###@+=%%+=====++++++@%+++++======+==+=+*******++++++++++++=======++===@%===+***++==%######%===
@@%%@@###@==%%=====%++*+++++++==+++++++=%+=+*****+++++++++++++++++++===+++++%====@@=+++++@@%#####===
=%@@@####%@%@%=====%+++++*===%%@@####==%==+*****+++++++++++++++++++++==***++=++=+@@@@=+++=@#@%###@=+
=%@@@####@%@%@=====%+++++*=@######@@%=====+**********+++++++****+++++==+****=%=++%@@@@@==++@#@@@###%
===@@###@%=@@@=====%+++++=@@##@###%=%=+==++************************++===****=+++*=@@@@##@%==@#######
=++=@###@=%@@#%====%++*=%%@@%##@===%=++=++%+************************+===***+==++*%%@@@@###@==@######
++++%###==%%@@#====%++*==@%#=+===%==+==+++==************************+===*++==+**%@@%%%%%####%%#@####
*++++@#%=%%%@@#%====+*+=%%*%=%%%==+++=++****************************+===*+++**=@@@@@%%%==@###@%@####
*+*+++#@%@%@@@#@==+=+*=%@=*++=+****+++=+****************************++==+=+++%@@@@@##%%=%@=@##%@@###
+****+=##@%@@@##=+++*+@%**++=+****=%=+++=*****====+*****************+===+==@@@@%%@@###@=+####@@=@###
+*****+@##@@@@@#=+++*=+**+++@=+***===+%+*++++%%@#@==%+**************+===+==@%%%%%%#####%=%######=###
*****+=@###@@@%#%+++*%****++%%=***+=+++*****+++==%=+***************++===+==@%%%%%=@#####%%######%=##
****+=%@@###@@@@@++=*+%+**=++=@+***%==***=======++*****************++======%@%%%%+%######=#######+=#
***+=+@@@###@@@@%++=**+%%+==+++=+****+**+=++++********************++=%===%=%#===%%+%#####%#######++@
+++%==@@@@##@@@@@+==+*==%%==++*++*******==+**********************+=======%=#%#@+=@#==@###########+=@
+=%=+@@@@@@##@@@@+==++===%==++*++++++***==+*******************+==========@=@###==@@@#@%@@###@@@#@=##
=%=+%@@@@@@##@@@@=%=+*====%=+++++****++***==****************+======+==%+%@%@###%=#@##@@#@@@@#@@@%@##
%%+=%@@@@@@#@@@@@+%%=+====%==+*+******************+******+=======+*+===+@@=%@@@%%#@##@@@@@@@@@@@@@##
@=+=@@@@@@##@@@@@=%===+===%=%%=++*************=#@%%=+*+=======++***+===+%@@@%@@%@@@@@@@@@@@@@@@@@###
@=+%@@@@@@##@@@@@=@%%=+%==%%%@@@++**************%=+++++++++=++*****+==+=+=@@@@@@@@@@@@@@@@@@@@@@@@@@
@+%@@@@@@###@@@@@=@%=====%=%@@@@@%++************=+++++++++++*******====+*****==%%%@%===%@@@@@@@@@@@@
%=%@@@@@####@@@@@%@#====%%%%@@@@@@@%+***********=++++++++****++***+===+****++++++*****++++++%%@@@@@@
=@%@@@@@####@@@@%@@#@==+===%@@@@@@@+***********+@+++++*****++++++==+=*=****************+++++++++++*+
%%@@@@@#####@@@@@@@##%=++===@@====+***********+=%====+*********+===++*++******************++++++++++
@%@@@@@####@@@@@@@@%===++=+==%==*************++=++==++*******+++=+=**+*=*********************+++++++
%@@@@@@####@@@@@@%+=%===+++=%%==***********+++=+++**+++******+==++******=***:*****************++++**
*/





/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+*::*:*+*::::::::::::*=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=*::::::::+=+:**::::**+*:::::::::+=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=:::*:::::::+=:**::::*==+::::::::::::::::*%@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=:::**::::::::=**:::::+=+::::::::::::::::::::::*%@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*:::**:::::::::+*:::::++::::::::::::::::::*:::::+*::+@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@*::::*:::::::::**+::::+*:::::::::::::::::::::*::::::*:::+@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@+::::+:::::-----:*:---*----------:*::::::::::::::::::::=**=:%@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@%::::-*--------:::+:::+::::::::::::*+::::::::---::*::::::*=+*=:+@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@+----:::::::::::::+::+::::::::::::::=::::::::::::::::::::::*:=*+:*@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@+--::*::::::::::::*::*::::::::::::::+=::::::::::::::::::::::*::+**:*@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@=::::*:::::::::::::**:::::::::::::::==*:::::::::::::::*:::::::*::+*::*@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@=::::*:::::::::::::*+::::::::::::::*==+::::::::::*:::::+:::::::*:::**::+@@@@@@@@@@@@@
@@@@@@@@@@@##@@@@@%::::+*:::::::::::**+::::+::+::::::+%***::**::::::*:::::+::::::::::::+-::%@@@@@@@@@@@@
@@@@@@@@@@#@@@@@@@**::*+:::::::::::+*+:::**::+::::::=*:*+:::=:::::::+:::::+:::::::*::::+::-:@@@@@@@@@@@@
@@@@@@@###@@@@@@@*****=::::::::::::+****+**+=*****++**+=**:++*::*::*+:::::+::::::::+::::*:::+@@@@@@@@@@@
@@@@########@@@@*****=:***********+***+**+*+*****+::::+***=%+******++:*:::*::::::::+::::*::::@@@@@@@@@@@
@###########@@@=+***=********+****+*+*+*::+*****:::::***=:*+*+****+:*********:::+:*+*::**::::+@@@@@@@@@@
############@@%=***+=************+*+:::::+**+*****:::***::+*=****+:::+*+*****::=+:+*+::*:::::*@@@@@@@@@@
##########@@@@+***+=********+****++::**+%####@@####=:**::+++****+::::*++*+****:=+:+:+::+*:::::%@@@@@@@@@
###########@@++***==*******+*****+*::::::::::::::::+##+:+*+*****::::::+*+++****==**::****:::::+@@@@@@@@@
##########@@%+***+=+*******+****++:::::------------:::=+:::::::::::::::++*+******+*::*+***+::**@@@@@@@@@
#########@@@*+***==*******+*****=:::::*:------@@@@%+--:::::::::::::::::::**+**+:**:::+=+**=****@@@@@@@@@
#########@#*+***+==*******+****+:::::::+:----+=+=-*%---:::::::::::::::::*****:::::::*%%+**=****%@@@@@@@@
########@#+*+***==+*******+****+::::::::*=---:****+*--:::::::::--:::::=##@####%+:::*==%=**=****=@@@@@@@@
#########=*+***+=%*******+******::*****:*********:--:::::::::::::::-:::---::::=#%**===%**++****=@@@@@@@#
########=**+***===*******=****+:::****+************:::::::::::::::::-+#@@=----::@=====%+*=+****+@@@@@###
#######=+*****+==+*******=*****::::******************::::::::::::::::=%+*%-----:*@====%+*=******@@@###@@
######++**+***+=*+******+=*****:::::******************:::::::::::::::=**=*-----*======%**+*****+%###@@@#
#####++**++***==*+******+=***+:::::::***************:::::::::::::::::**------*%=%===%++*+******%%@@@@@@@
###@*+**+%***+%**+******==***+:::::::::::::***:*:::::::::::::::::**********+*==%%====*+*+*+****=@@@@@@@@
##@*+**===***=***+******==***%+::::::::::::::::::::::::::::::::::******+*+**===%%===*=*==*+****%%@@@@@@@
#%*+**==++***=***+******==***%%+:::::::::::::::::::::::::::::::::*:*****+++=%==%%==+*=*@@******%%@@@@@@@
=+**+==%+***=**********+==***%=+*::::::::::::::::::::::::::::::::::*******===%=@%=+*+*+@@=****+@@@@@@##@
+**=*=%*+**++****+=****+=%***@=+**:::::::::::::::::::***:::::::::::::****====%=@==++++*@%*+***%@@#@#####
*+**==+*+**+*****==****+=%+**%%*****::::::::::::::::*****+:::::::::::::*=====%=%==++*++%*@***+@%@@######
***==%*++*+*****===+****%%=**%=*******:::::::::::::::::::::-::::::::::*=======%%==+**+=%@%***@=@########
**=%%**=*+*****+===+****%%=+*=+********+*:::::::::::::::::::::::::::*=========%%==+***%@#***%@#@########
+=%=+*+=+******==+*+=***%==%*+::***********::::::::::::::::::::::*===%=========%+=+***%@+*=@@###########
%===*:=+:::::*==***==+**+==%%**::***********+:::::::::::::::::+===%==%====+====%+==***=+%@@#############
==@::*=::::::==*::+==%***%%==++*:::***********+*:::::::::*========%==%===+*+===%+*=****@@###############
%=+::+::::::+*:::*====%**+%==::*+:::*************+*::+==%==========%=%===***=====*=**+*=@###############
:+::+::::::+:::::+====%%+*=#@#####@####%+********===%===%===========%=%=*****==+=**+*+**################
:*:*:::::*+:::::*====%===%*@################@=***@==%====%===========%%+*****==+=**+*=**=###############
*::*::::*::::::*==%%%#+%%+:++::::::+%@##########%%==%====%==========**=+*****+=+=*****@**###############
+::::::*:::::::==%+:=@:::**+=@*:::::::::::=@#####%=%%====%=========*****+*****===+**+*%@*=##############
**:::*:::::::*=%%:::%%:::::::::*=*:***::::::::=##=%%=====%=+=====+*******+****===+***+=@@*@#############
+:::::::::::*==:::::@%::::::::::::*=*:::*:::::::%=%%=====%%=*===+*********+***+++=***+*##@+#############
*::::::::::+%::::::*#=:::::::::::::::*=*::**::::===%=====%%%+*%=+*****::*******++=****+%##%%############
*::::::::*=*::::::*%#%::::::::::::::::::*=*::***::+++=%===%%%**%=***::::::==*+*++=+****%###=############
********=*::::::=@####=::::::::::::::::::::++:::::::::::*%%==%**%+*:::::::*==*+++==*****###@=###########
******=:::::+#########@=++++::::::::::::::::::*==:::::::*=++#%%=:=+::::::::*==:++==*****+###=@##########
****=::::*+*=@#####@%===***+++++:::**:::::::::::::*==+:::::::+@::+*+:::::::::%*:*%=+*****=##@=##########
*+%*::::+****=####%*******+::::**+=:::*:::::::::::*=%=::::::::*+%:::+*:::::::*=:**%=******%##*##########
=*::::*++****%#####%****+**+++++***+@+::+::::::::::::*:::::::::**==:::**::::::=****%*******##+%#########
:::::+::+***=@#########%******+******=+*::**:::::::::::::::::::::*:@=::::+*:*:*=****=******+#++#########
::::+=+*****++#########@++***+@%+*++**+++:::**::::::::::::::::::::*:*#*::::++**=*****+******=**#########
:::++++%+***+@########=++***+@@@@=****=::*+:::**:::::::::::::::::::**:=@*::::+%%*************+*@########
::*=+++@#@@############=****+++++@@@%*++:+++::::+::::::::::::::::::::+**%@*:::*=+******+*+*****@########
=:##@@#############%+++*++::*=*++=++++++++*@=::::**:::::::::::::::::::::+%@@::**+*******+******@########
*/





#include "s21_Engine.h"
#include "s21_Stack.h"





#endif  // SRC_S21_CALCULATE_H_
