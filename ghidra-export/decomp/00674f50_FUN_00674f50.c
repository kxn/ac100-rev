// func FUN_00674f50 @ 00674f50 size=68

void FUN_00674f50(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = &PTR_memory_check_init_00731168; (code *)*ppuVar1 != (code *)0xffffffff;
      ppuVar1 = ppuVar1 + -1) {
    (*(code *)*ppuVar1)();
  }
  return;
}

