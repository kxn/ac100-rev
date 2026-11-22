// func mc_mem_free @ 0051dd80 size=24

void mc_mem_free(void)

{
  mckernelVmManageFree();
  return;
}

