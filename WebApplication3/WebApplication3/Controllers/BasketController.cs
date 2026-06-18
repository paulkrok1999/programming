using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using WebApplication3.Models;

namespace WebApplication3.Controllers
{
    public class BasketController : Controller
    {
        // GET: BasketController
        public ActionResult Index(int basketid)
        {
            var basked = BasketRepos.GetBackid(basketid);
            return View(basked); ;
        }
    }
}
