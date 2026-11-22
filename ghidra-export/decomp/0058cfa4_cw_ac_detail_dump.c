// func cw_ac_detail_dump @ 0058cfa4 size=1

void cw_ac_detail_dump(void)

{
  uint uVar1;
  
  if (ac != 0) {
    puts("\n***************************AC INFO******************************");
    for (uVar1 = 0; uVar1 < *(uint *)(ac + 0x18); uVar1 = uVar1 + 1) {
      cw_ac_thread_detail_dump(uVar1);
    }
    (*(code *)PTR_puts_00758f90)
              ("\n*****************************END********************************");
    return;
  }
  return;
}

