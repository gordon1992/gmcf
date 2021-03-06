
#ifndef TILE_H_
#define TILE_H_

// Tile.rb
//
// :title: Service-based SoC project - SBA Tile class
//
//
// *
// *  (c) 2004-2009 Wim Vanderbauwhede <wim@dcs.gla.ac.uk>
// *
//
// $Id: Tile.rb 2532 2009-04-22 16:15:08Z socgroup $


#include "./ServiceConfiguration.h"
#include "./Transceiver.h"
#include "./ServiceManager.h"
#include "./Memory.h"
#include "./LookupTable.h"
#include "./InclusionSetTable.h"
#include "Services.h"
#include "Base/Tile.h"
#include "Base/System.h"

using namespace std;
using namespace SBA;
/**
 * Ideally, each service has its own configuration.
 * Therefore, we should store the per-service confgiration in an array.
 * But for now, we use a common configuration file
 */
namespace SBA {
#if USE_THREADS==1
    void *run_tile_loop(void*);
#endif
class Tile : public Base::Tile {
		public:
		Base::System* sba_system_ptr;
		Service service;
		ServiceAddress address;
		bool status;
		//Transceiver transceiver;
		Transceiver *transceiver;
		ServiceManager service_manager;
		Memory data_store;
		Memory code_store;
        LookupTable lookup_table;
		Services service_core;
		bool finished;
		InclusionSetTable incl_set_tbl;
	Tile(Base::System* sba_s_, Service& s_, ServiceAddress addr_)
	: sba_system_ptr(sba_s_), service(s_), address(addr_),
	status(false),
	//transceiver(sba_s_,this,s_,addr_),
	service_manager(sba_s_,this,s_,addr_),
	service_core(sba_s_,this,s_,addr_,0),
	finished(false)
	 {

		transceiver = new Transceiver(sba_s_,this,s_,addr_);

	 };	// END of constructor

	Tile()
	: sba_system_ptr(NULL), service(0), address(0), status(false),
	//transceiver(sba_system_ptr,this,service,address),
	service_manager(sba_system_ptr,this,service,address),
	service_core(sba_system_ptr,this,service,address,0),
	finished(false)
	{

		transceiver = new Transceiver(sba_system_ptr,this,service,address);
	};
/*
 Main methods
*/
	void run();

#if USE_THREADS==1
    pthread_t tid;
    pthread_attr_t attr;
    //void* tstatus;
    void run_th ();
#endif

}; // end

} // namespace SBA


#endif // TILE_H_
