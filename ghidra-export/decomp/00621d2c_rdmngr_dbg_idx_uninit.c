// func rdmngr_dbg_idx_uninit @ 00621d2c size=56

void rdmngr_dbg_idx_uninit(void)

{
  if (g_rdmngr_dbg_idx != 0) {
    FUN_00407df0();
    g_rdmngr_dbg_idx = 0;
  }
  return;
}

