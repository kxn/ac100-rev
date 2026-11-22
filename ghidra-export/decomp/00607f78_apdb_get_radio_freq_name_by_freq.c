// func apdb_get_radio_freq_name_by_freq @ 00607f78 size=40

undefined * apdb_get_radio_freq_name_by_freq(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 < 2) {
    puVar1 = (&PTR_s_2_4GHz_00702480)[param_1];
  }
  return puVar1;
}

