# Este script genera archivos dia con las clases que programamos.
# Hay que correrlo en la raíz del proyecto. Internamente se maneja en frontend/modules/ 

RUN_PATH="frontend/modules/"
dirs=$(ls -1 $RUN_PATH | grep -v .inc | grep -v .sh | grep -v .php | grep -v docmanager | grep -v email_template | grep -v graph | grep -v person | grep -v pim | grep -v quotation | grep -v setup | grep -v timereg | grep -v todo | grep -v utils | grep -v project | grep -v reports | grep -v scheduler | grep -v search | grep -v organization | grep -v crm | grep -v dirs | grep -v employee | grep -v notes)
mkdir clases

for i in $dirs;
do
		autodia -l php -o clases/$i.dia $RUN_PATH$i/*.inc;
done;
