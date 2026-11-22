// func _uac_wsta_freq_cmp @ 00630744 size=88

bool _uac_wsta_freq_cmp(int param_1,char *param_2)

{
  undefined4 uVar1;
  char *__s2;
  int iVar2;
  bool bVar3;
  
  uVar1 = rdmngr_db_generate_rd_id(*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24));
  uVar1 = rdmngr_db_get_rd_freq_band(uVar1);
  __s2 = (char *)apdb_get_radio_freq_name_by_freq(uVar1);
  bVar3 = true;
  if (__s2 != (char *)0x0) {
    iVar2 = strcasecmp(param_2,__s2);
    bVar3 = iVar2 != 0;
  }
  return bVar3;
}

