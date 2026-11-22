// func wsta_db_print_all @ 0063981c size=96

void wsta_db_print_all(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < l_wsta_profile; uVar1 = uVar1 + 1) {
    wsta_db_print_entry(DAT_007cc6c8 + uVar1 * 0x80);
  }
  return;
}

