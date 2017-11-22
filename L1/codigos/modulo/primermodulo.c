#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* Cargar el modulo */
int simple_init(void)
{
  printk(KERN_INFO "Cargando el Modulo :)\n");
  return 0;
}

/* Remover el modulo */
void simple_exit(void) 
{
  printk(KERN_INFO "Removiendo el Modulo :(\n");
}

/* Punto de entrada y salida */
module_init( simple_init );
module_exit( simple_exit );
/* Standard info */
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Primer Modulo SO ULA A-2016");
MODULE_AUTHOR("ULA SO");
