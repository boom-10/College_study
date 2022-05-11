import Vue from 'vue'
import Router from 'vue-router'

Vue.use(Router)

/* Layout */
import Layout from '@/layout'

/**
 * Note: sub-menu only appear when route children.length >= 1
 * Detail see: https://panjiachen.github.io/vue-element-admin-site/guide/essentials/router-and-nav.html
 *
 * hidden: true                   if set true, item will not show in the sidebar(default is false)
 * alwaysShow: true               if set true, will always show the root menu
 *                                if not set alwaysShow, when item has more than one children route,
 *                                it will becomes nested mode, otherwise not show the root menu
 * redirect: noRedirect           if set noRedirect will no redirect in the breadcrumb
 * name:'router-name'             the name is used by <keep-alive> (must set!!!)
 * meta : {
    roles: ['admin','editor']    control the page roles (you can set multiple roles)
    title: 'title'               the name show in sidebar and breadcrumb (recommend set)
    icon: 'svg-name'/'el-icon-x' the icon show in the sidebar
    breadcrumb: false            if set false, the item will hidden in breadcrumb(default is true)
    activeMenu: '/example/list'  if set path, the sidebar will highlight the path you set
  }
 */

/**
 * constantRoutes
 * a base page that does not have permission requirements
 * all roles can be accessed
 */
export const constantRoutes = [
  {
    path: '/login',
    component: () => import('@/views/login/index'),
    hidden: true
  },

  {
    path: '/404',
    component: () => import('@/views/404'),
    hidden: true
  },

  {
    path: '/',
    component: Layout,
    redirect: '/dashboard',
    children: [{
      path: 'dashboard',
      name: 'Dashboard',
      component: () => import('@/views/dashboard/index'),
      meta: { title: '首页', icon: 'dashboard' }
    }]
  },

  {
    path: "/guide",
    name: "Guide",
    component: Layout,
    children: [{
      path: '/guide',
      name:"guide",
      component: () => import("@/views/guide"),
      meta:{title:"引导",icon:"el-icon-document"}
    }]
  },

  {
    path: '/selection',
    name:'Selection',
    component: Layout,
    meta:{title:"课程选择",icon:'el-icon-set-up'},
    children: [{
      path: "/timetable",
      name: "Timetable",
      component: () => import('@/views/course_selection/show_timetable'),
      meta:{title:"课程表显示"}
    },{
      path: "/timeSelection",
      name: "TimeSelection",
      component:()=> import('@/views/course_selection/time_selection'),
      meta:{title:"按时间选课"}
    },{
      path: "/subSelection",
      name: "SubSelection",
      component:()=> import('@/views/course_selection/sub_selection'),
      meta:{title:"按课程选课"}
    }]
  },
  
  {
    path: "/selected",
    name: "Selected",
    component: Layout,
    children: [{
      path: '/selected',
      name:"Selected",
      component: () => import("@/views/selected_courses"),
      meta:{title:"已选课程界面",icon:"el-icon-lock"}
    }]
  },

  {
    path: "/recommend",
    name: "Recommend",
    component: Layout,
    children: [{
      path: '/recommend',
      name:"Recommend",
      component: () => import("@/views/recommed"),
      meta:{title:"课程推荐",icon:"el-icon-dessert"}
    }]
  },

  {
    path: "/feedback",
    name: "Feedback",
    component: Layout,
    children: [{
      path: '/feedback',
      name:"Feedback",
      component: () => import("@/views/feedback"),
      meta:{title:"反馈",icon:"el-icon-edit-outline"}
    }]
  },



  // 404 page must be placed at the end !!!
  { path: '*', redirect: '/404', hidden: true }
]

const createRouter = () => new Router({
  // mode: 'history', // require service support
  scrollBehavior: () => ({ y: 0 }),
  routes: constantRoutes
})

const router = createRouter()

// Detail see: https://github.com/vuejs/vue-router/issues/1234#issuecomment-357941465
export function resetRouter() {
  const newRouter = createRouter()
  router.matcher = newRouter.matcher // reset router
}

export default router
