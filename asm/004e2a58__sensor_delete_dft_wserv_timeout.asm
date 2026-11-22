; func _sensor_delete_dft_wserv_timeout @ 0x004e2a58 size=0x64
  4e2a58:	27bdffd8 	addiu	sp,sp,-40
  4e2a5c:	2405ffff 	li	a1,-1
  4e2a60:	afb00018 	sw	s0,24(sp)
  4e2a64:	3c100077 	lui	s0,0x77
  4e2a68:	afb20020 	sw	s2,32(sp)
  4e2a6c:	3c120073 	lui	s2,0x73
  4e2a70:	afb1001c 	sw	s1,28(sp)
  4e2a74:	2411ffff 	li	s1,-1
  4e2a78:	afbf0024 	sw	ra,36(sp)
  4e2a7c:	0c1020b4 	jal	0x4082d0
  4e2a80:	8e04862c 	lw	a0,-31188(s0)
  4e2a84:	3c020077 	lui	v0,0x77
  4e2a88:	8e441af4 	lw	a0,6900(s2)
  4e2a8c:	10910004 	beq	a0,s1,0x4e2aa0
  4e2a90:	ac40864c 	sw	zero,-31156(v0)
  4e2a94:	0c1774de 	jal	0x5dd378
  4e2a98:	00000000 	nop
  4e2a9c:	ae511af4 	sw	s1,6900(s2)
  4e2aa0:	8e04862c 	lw	a0,-31188(s0)
  4e2aa4:	8fbf0024 	lw	ra,36(sp)
  4e2aa8:	8fb20020 	lw	s2,32(sp)
  4e2aac:	8fb1001c 	lw	s1,28(sp)
  4e2ab0:	8fb00018 	lw	s0,24(sp)
  4e2ab4:	08101fcc 	j	0x407f30
  4e2ab8:	27bd0028 	addiu	sp,sp,40
