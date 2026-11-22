// func apmngr_support_capacity_init @ 0052a9a4 size=76

undefined4 apmngr_support_capacity_init(void)

{
  cap_supp = cap_supp | 0x20001900;
  DAT_007c5488 = DAT_007c5488 | 0xc000c04;
  DAT_007c548c = DAT_007c548c | 0xaa6e2;
  return 0;
}

