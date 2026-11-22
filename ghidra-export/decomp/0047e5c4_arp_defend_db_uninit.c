// func arp_defend_db_uninit @ 0047e5c4 size=216

undefined4 arp_defend_db_uninit(void)

{
  if (DAT_007670f8 != 0) {
    FUN_00407f30();
    DAT_007670f8 = 0;
  }
  if (DAT_007670fc != 0) {
    FUN_00407f30();
    DAT_007670fc = 0;
  }
  if (DAT_00767100 != 0) {
    FUN_00408160();
    DAT_00767100 = 0;
  }
  if (DAT_00767104 != 0) {
    FUN_00407df0();
    DAT_00767104 = 0;
  }
  if (DAT_0076710c != 0) {
    FUN_00407df0();
    DAT_0076710c = 0;
  }
  if (g_arp_defend_db_ptr != 0) {
    FUN_004080b0();
    g_arp_defend_db_ptr = 0;
  }
  g_arp_defend_data = 0;
  return 0;
}

