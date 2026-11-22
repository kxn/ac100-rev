// func _uac_rdmngr_rd_name_cmp @ 00624348 size=88

bool _uac_rdmngr_rd_name_cmp(int param_1,char *param_2)

{
  char *__s2;
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if (((param_1 != 0) && (param_2 != (char *)0x0)) &&
     (__s2 = (char *)apdb_get_radio_freq_name_by_freq((int)*(char *)(param_1 + 8)),
     __s2 != (char *)0x0)) {
    iVar1 = strcasecmp(param_2,__s2);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}

