; func cw_priv_chnl_scan_free @ 0x005ad63c size=0xb0
  5ad63c:	27bdffd0 	addiu	sp,sp,-48
  5ad640:	afb30028 	sw	s3,40(sp)
  5ad644:	afbf002c 	sw	ra,44(sp)
  5ad648:	afb20024 	sw	s2,36(sp)
  5ad64c:	afb10020 	sw	s1,32(sp)
  5ad650:	afb0001c 	sw	s0,28(sp)
  5ad654:	8c900010 	lw	s0,16(a0)
  5ad658:	1200001c 	beqz	s0,0x5ad6cc
  5ad65c:	00809821 	move	s3,a0
  5ad660:	92020001 	lbu	v0,1(s0)
  5ad664:	10400016 	beqz	v0,0x5ad6c0
  5ad668:	00000000 	nop
  5ad66c:	8e020004 	lw	v0,4(s0)
  5ad670:	10400013 	beqz	v0,0x5ad6c0
  5ad674:	00008821 	move	s1,zero
  5ad678:	92020001 	lbu	v0,1(s0)
  5ad67c:	0222102a 	slt	v0,s1,v0
  5ad680:	1040000c 	beqz	v0,0x5ad6b4
  5ad684:	8e040004 	lw	a0,4(s0)
  5ad688:	001190c0 	sll	s2,s1,0x3
  5ad68c:	00922021 	addu	a0,a0,s2
  5ad690:	8c840004 	lw	a0,4(a0)
  5ad694:	1080fff8 	beqz	a0,0x5ad678
  5ad698:	26310001 	addiu	s1,s1,1
  5ad69c:	0c101f7c 	jal	0x407df0
  5ad6a0:	00000000 	nop
  5ad6a4:	8e020004 	lw	v0,4(s0)
  5ad6a8:	00529021 	addu	s2,v0,s2
  5ad6ac:	0816b59e 	j	0x5ad678
  5ad6b0:	ae400004 	sw	zero,4(s2)
  5ad6b4:	0c101f7c 	jal	0x407df0
  5ad6b8:	00000000 	nop
  5ad6bc:	ae000004 	sw	zero,4(s0)
  5ad6c0:	0c101f7c 	jal	0x407df0
  5ad6c4:	02002021 	move	a0,s0
  5ad6c8:	ae600010 	sw	zero,16(s3)
  5ad6cc:	8fbf002c 	lw	ra,44(sp)
  5ad6d0:	00001021 	move	v0,zero
  5ad6d4:	8fb30028 	lw	s3,40(sp)
  5ad6d8:	8fb20024 	lw	s2,36(sp)
  5ad6dc:	8fb10020 	lw	s1,32(sp)
  5ad6e0:	8fb0001c 	lw	s0,28(sp)
  5ad6e4:	03e00008 	jr	ra
  5ad6e8:	27bd0030 	addiu	sp,sp,48
