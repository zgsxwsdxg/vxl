//-*- c++ -*-------------------------------------------------------------------
#ifndef vcl_sunpro_set_txx_
#define vcl_sunpro_set_txx_

#include <vcl/vcl_set.h>
#include <vcl/vcl_compiler.h>

#if 0 // has member templates
#define VCL_SET_INSTANTIATE_MT_InputIterator(settype, T, Comp, InputIterator)\
template settype<T, Comp >::settype(InputIterator, InputIterator);\
template settype<T, Comp >::settype(InputIterator first, InputIterator last, Comp const&);\
template void settype<T, Comp >::insert(InputIterator first, InputIterator last)

#else
#define VCL_SET_INSTANTIATE_MT_InputIterator(settype, T, Comp, InputIterator) /* no-op */
#endif

#define VCL_SET_INSTANTIATE_ITERATOR(InputIterator, Distance)\
template void std :: __distance (InputIterator , InputIterator , Distance& , std::bidirectional_iterator_tag ) 



#define VCL_SET_INSTANTIATE(T, Comp)\
template class vcl_set<T, Comp >; \
template class vcl_set<T, Comp >::__rep_type; \
VCL_SET_INSTANTIATE_ITERATOR(vcl_set<T VCL_COMMA Comp >::iterator, unsigned)

#endif
