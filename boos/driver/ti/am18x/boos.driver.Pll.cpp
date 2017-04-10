/** 
 * Target processor phase-locked loop controller factory. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.Pll.hpp"
#include "boos.driver.PllController.hpp"

namespace driver
{
  /**
   * Returns the register interface of a target processor.
   *
   * @return target processor register interface, or NULL if error has been occurred.
   */
  ::driver::Pll* Pll::create()
  {
    ::driver::PllController* resource;
    resource = new PllController();
    if(resource == NULL) return NULL; 
    if(resource->isConstructed()) return resource;       
    delete resource;
    return NULL;  
  }
  
  /**
   * Initializes the driver.
   *
   * @param config a target processor configuration.
   * @return true if no errors have been occurred.
   */   
  bool Pll::init(const ::Configuration config)
  {
    return PllController::init(config);
  }

  /**
   * Deinitializes the driver.
   */
  void Pll::deinit()
  {
    PllController::deinit();  
  }  
}