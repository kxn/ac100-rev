// func apdb_print_global @ 0060c580 size=1

void apdb_print_global(void)

{
  undefined *puVar1;
  int iVar2;
  
  printf("vendor type:\t%d\n\r",vendor_type);
  printf("sale method:\t%s\n\r",&sales_method);
  printf("support product type bitmap:\t%32x\n\r",support_product_type_bitmap);
  printf("extra sale method:\t");
  puVar1 = &extra_sales_methods;
  for (iVar2 = 0; iVar2 < extra_sales_method_count; iVar2 = iVar2 + 1) {
    printf("%s ",puVar1);
    puVar1 = puVar1 + 0x81;
  }
  (*(code *)PTR_puts_00758f90)(&DAT_006ea0e8);
  return;
}

