// func _mesh_discover_ap_cmp_func @ 004b6910 size=48

bool _mesh_discover_ap_cmp_func(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    iVar1 = memcmp((void *)(param_1 + 0xc),param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

