// func systime_destroy @ 006667f0 size=1

void systime_destroy(void)

{
  if (systime_register_list != 0) {
    FUN_00407df0();
    systime_register_list = 0;
  }
  return;
}

