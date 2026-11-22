// func isStaAccess @ 0042501c size=124

bool isStaAccess(int param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_90 [32];
  undefined4 local_70;
  undefined1 local_6c;
  undefined1 local_6b;
  
  memset(auStack_90,0,0x80);
  iVar1 = wsta_db_get_entry_by_mac(param_2,auStack_90);
  bVar2 = false;
  if ((iVar1 == 0) && (iVar1 = uac_wservice_get_wserv_id(local_70,local_6c,local_6b), iVar1 != -1))
  {
    bVar2 = iVar1 == param_1;
  }
  return bVar2;
}

