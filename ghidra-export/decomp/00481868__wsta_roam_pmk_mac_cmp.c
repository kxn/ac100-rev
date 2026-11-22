// func _wsta_roam_pmk_mac_cmp @ 00481868 size=48

bool _wsta_roam_pmk_mac_cmp(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    iVar1 = memcmp((void *)(param_1 + 0x10),param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

