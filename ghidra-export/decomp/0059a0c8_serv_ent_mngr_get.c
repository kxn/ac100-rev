// func serv_ent_mngr_get @ 0059a0c8 size=44

undefined4 serv_ent_mngr_get(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0xffff) < 4) {
    uVar1 = (&g_serv_ent_mngr)[param_1 & 0xffff];
  }
  return uVar1;
}

