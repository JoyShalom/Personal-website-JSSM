
import Vue from 'vue'
import Router from 'vue-router'
import HomePage from '@/components/HomePage'
import AcademicPage from '@/components/AcademicPage'
import OodPro1 from '@/components/OOD/OodPro1'
import OodPro2 from '@/components/OOD/OodPro2'
import OodPro3 from '@/components/OOD/OodPro3'
import OodPro4 from '@/components/OOD/OodPro4'
import MainPage from '@/components/mainPage'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/home',
      name: 'HomePage',
      component: HomePage
    },
    {
      path: '/academic',
      name: 'AcademicPage',
      component: AcademicPage
    },
    {
      path: '/oodPro1',
      name: 'No SQL Database',
      component: OodPro1
    },
    {
      path: '/oodPro2',
      name: 'Remote Code Publisher',
      component: OodPro2
    },
    {
      path: '/oodPro3',
      name: 'Code Publisher',
      component: OodPro3
    },
    {
      path: '/oodPro4',
      name: 'Remote Code Publisher using WPF',
      component: OodPro4
    },
    {
      path: '/',
      name: 'MainPage',
      component: MainPage
    }
  ]
})
