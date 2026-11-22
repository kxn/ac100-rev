// func acpdt_product_info_dump @ 006662d4 size=1

void acpdt_product_info_dump(void)

{
  printf("device model: %s\n",g_acpdt_info);
  printf("software ver: %d.%d.%d Build %d Rel.%05d\n",*(undefined4 *)(g_acpdt_info + 0x80),
         *(undefined4 *)(g_acpdt_info + 0x84),*(undefined4 *)(g_acpdt_info + 0x88),
         *(undefined4 *)(g_acpdt_info + 0x8c),*(undefined4 *)(g_acpdt_info + 0x90));
  printf("hardware ver: %d.%d\n",*(undefined4 *)(g_acpdt_info + 0x94),
         *(undefined4 *)(g_acpdt_info + 0x98));
  return;
}

