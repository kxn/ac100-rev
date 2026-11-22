// func uac_com_is_dev_mac @ 005138d8 size=120

bool uac_com_is_dev_mac(void *param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 local_18;
  undefined2 local_14;
  
  bVar2 = false;
  local_18 = 0;
  local_14 = 0;
  if (param_1 != (void *)0x0) {
    iVar1 = uac_com_get_dev_mac(&local_18);
    if (iVar1 == 0) {
      iVar1 = memcmp(&local_18,param_1,6);
      bVar2 = iVar1 == 0;
    }
  }
  return bVar2;
}

