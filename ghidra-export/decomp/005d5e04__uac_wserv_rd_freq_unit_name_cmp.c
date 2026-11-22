// func _uac_wserv_rd_freq_unit_name_cmp @ 005d5e04 size=132

bool _uac_wserv_rd_freq_unit_name_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar2;
  int iVar1;
  bool bVar3;
  
  bVar3 = true;
  if (param_3 != (char *)0x0) {
    cVar2 = rdmngr_db_get_rd_freq_band(param_2);
    iVar1 = strcasecmp(param_3,"2.4GHz");
    if ((iVar1 != 0) || (bVar3 = false, cVar2 != '\0')) {
      iVar1 = strcasecmp(param_3,"5GHz");
      bVar3 = true;
      if (iVar1 == 0) {
        bVar3 = cVar2 != '\x01';
      }
    }
  }
  return bVar3;
}

