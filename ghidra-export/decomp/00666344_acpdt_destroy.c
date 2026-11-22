// func acpdt_destroy @ 00666344 size=1

void acpdt_destroy(void)

{
  if (g_acpdt_info == 0) {
    FUN_00407df0(0);
    g_acpdt_info = 0;
  }
  return;
}

