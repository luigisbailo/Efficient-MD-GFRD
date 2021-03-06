import matplotlib
import numpy as np
import matplotlib.pyplot as pl

pl.style.use(['style1'])

# pl.figure(figsize=(5, 3))
f, ((ax1),(ax2)) = pl.subplots(2,1,sharex=True)

f.set_figheight(5)
f.set_figwidth(3.37)


data_burst = np.loadtxt("1.burst.txt")
data_GF = np.loadtxt("1.GF.txt")
filename = "1.data.txt"
param = np.loadtxt (filename)
ax1.set_xscale("log")
ax1.set_yscale("log")
ax1.plot(100000000/data_burst[:,0]/data_burst[:,0]/data_burst[:,0]/6.022,data_burst[:,2]/data_GF[:,2],color='#377EB8',marker='s',markersize=5,linestyle='None', label='MD-GFRD')
ax1.plot(100000000/data_burst[:,0]/data_burst[:,0]/data_burst[:,0]/6.022,data_burst[:,1]/data_GF[:,1],color='#4DAF4A',marker='o',markersize=5,linestyle='None', label='New scheme')	

text = r"$D = $" + str(int(1000*param[0])) + r"$\thinspace\frac{\mu m^2}{s}$"
box=dict(facecolor='white', edgecolor='grey', boxstyle='round')
ax1.text(0.168,0.8,text,fontsize=8,color='grey',bbox=box,horizontalalignment='center',verticalalignment='center',transform = ax1.transAxes)

ax1.text(0.075,0.92,'(A)',fontsize=10,transform = ax1.transAxes)
ax2.text(0.075,0.92,'(B)',fontsize=10,transform = ax2.transAxes)

# ax1.legend(loc=4,fontsize=10)


data_burst = np.loadtxt("2.burst.txt")
data_GF = np.loadtxt("2.GF.txt")
filename = "2.data.txt"
param = np.loadtxt (filename)
ax2.set_xscale("log")
ax2.set_yscale("log")
ax2.plot(100000000/data_burst[:,0]/data_burst[:,0]/data_burst[:,0]/6.022,data_burst[:,2]/data_GF[:,2],color='#377EB8',marker='s',markersize=5,linestyle='None', label='MD-GFRD')
ax2.plot(100000000/data_burst[:,0]/data_burst[:,0]/data_burst[:,0]/6.022,data_burst[:,1]/data_GF[:,1],color='#4DAF4A',marker='o',markersize=5,linestyle='None', label='New scheme')	

text = r"$D_1 = $" + str(int(1000*param[0])) + r"$\thinspace\frac{\mu m^2}{s}$"+"\n" +r"$D_2 = $" + str(int(1000*param[1])) + r"$\thinspace\frac{\mu m^2}{s}$"
box=dict(facecolor='white', edgecolor='grey', boxstyle='round')
ax2.text(0.175,0.65,text,fontsize=8,color='grey',bbox=box,horizontalalignment='center',verticalalignment='center',transform = ax2.transAxes)

ax2.legend(loc=4,fontsize=8)

ax2.set_xlim(0.0005,150)


ax1.set_ylim(0.005,1)
ax2.set_ylim(0.001,2)

ax1.set_yticks([0.01,0.1,1])
ax2.set_yticks([0.001,0.01,0.1,1])
# ax2.set_xticks([0.001,0.01,0.1,1,10,100])
ax1.tick_params('y',labelsize=10)
ax2.tick_params('both',labelsize=10)

ax2.set_ylabel(r'$\quad\quad\quad\qquad\qquad\quad Bursting\ probability$', fontsize=10)
ax2.set_xlabel(r'$Molar\ concentration\ [\mu M]$',fontsize=10)

pl.tight_layout()

f.subplots_adjust(wspace=0.05)
f.subplots_adjust(hspace=0.05)

#pl.show()
pl.savefig('eff.eps',dpi=600)
